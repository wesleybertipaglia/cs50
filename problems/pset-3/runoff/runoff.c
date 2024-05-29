#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    while (true)
    {
        tabulate();
        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int voter_i = 0; voter_i < voter_count; voter_i++)
    {
        for (int vote_i = 0; vote_i < candidate_count; vote_i++)
        {
            int candidate_i = preferences[voter_i][vote_i];
            if (!candidates[candidate_i].eliminated)
            {
                candidates[candidate_i].votes += 1;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    int half = voter_count / 2;
    for (int candidate_i = 0; candidate_i < candidate_count; candidate_i++)
    {
        if (candidates[candidate_i].votes > half)
        {
            printf("%s\n", candidates[candidate_i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int min = candidates[0].votes;
    for (int candidate_i = 1; candidate_i < candidate_count; candidate_i++)
    {
        if (!candidates[candidate_i].eliminated && candidates[candidate_i].votes < min)
        {
            min = candidates[candidate_i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    for (int candidate_i = 0; candidate_i < candidate_count; candidate_i++)
    {
        if (!candidates[candidate_i].eliminated && candidates[candidate_i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int candidate_i = 0; candidate_i < candidate_count; candidate_i++)
    {
        if (candidates[candidate_i].votes == min)
        {
            candidates[candidate_i].eliminated = true;
        }
    }
    return;
}

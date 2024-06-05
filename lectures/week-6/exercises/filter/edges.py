from PIL import Image, ImageFilter

dir = "lectures/week-6/exercises/filter/"
before = Image.open(f"{dir}bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save(f"{dir}out.bmp")

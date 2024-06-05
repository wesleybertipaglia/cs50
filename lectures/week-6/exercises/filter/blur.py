from PIL import Image, ImageFilter

dir = "lectures/week-6/exercises/filter/"
before = Image.open(f"{dir}bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save(f"{dir}out.bmp")

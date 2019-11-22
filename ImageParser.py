import sys
from PIL import Image
import os

if __name__ == '__main__':
    file_location = sys.argv[1]

    img = Image.open(file_location).convert('L')
    WIDTH, HEIGHT = img.size
    
    data = list(img.getdata())
    data = [data[offset:offset+WIDTH] for offset in range(0, WIDTH * HEIGHT, WIDTH)]


    #Open the text file to write the data to
    file = open('outputFile.txt', 'w')

    #Write the information to the file
    for row in data:
        for col in row:
            file.write(str(col))
            file.write('\n')
        file.write('-1\n')
        

    #Close the file
    file.close()

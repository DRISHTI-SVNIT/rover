import cv2 as cv  
import numpy as np 

blank = np.zeros((500,500,3),dtype = 'uint8') #uint8 is a data type of an image

#paint image
blank[200:300,300:400] = 0,0,255
cv.imshow('red',blank)

#draw
# rectangle (img , pt1 , pt2 , color , thickness , linetype=none)
cv.rectangle(blank , (0,0),(250,250),(0,255,0),thickness =2)
#circle(img , center , radius , color , thickness , linetype )
cv.circle(blank , (blank.shape[1]//2,blank.shape[0]//2),(0,255,0),thickness =2)
#draw a line
#put a text
#make a blured  area to write text onto it  

cv.waitKey(1000)
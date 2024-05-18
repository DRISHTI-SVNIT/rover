#not mask shape and shape of image must be same

import cv2 as cv
import numpy as np

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

blank = np.zeros(img.shape[:2],dtype = 'uint8') 

circle = cv.circle(blank.copy(),(img.shape[1//2],img.shape[0]//2),100,(255,255,255),-1)
rectangle = cv.rectangle(blank.copy(),(30,30),(400,400),(255,255,255),-1)

mask = cv.bitwise_and(circle,circle,mask = rectangle)
cv.imshow('mask',mask)

masked = cv.bitwise_and(img,img,mask = mask)
cv.imshow('masked',masked)
cv.waitKey(3000)
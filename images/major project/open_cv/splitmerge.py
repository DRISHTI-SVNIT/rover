import cv2 as cv
import numpy as np

img = cv.imread('photos/banswara.jpg')
cv.imshow("Image",img)

blank = np.zeros(img.shape[:2],dtype='uint8')

b,g,r = cv.split(img)

blue = cv.merge([b,blank,blank])
green = cv.merge([blank,g,blank])
red = cv.merge([blank,blank,r])

cv.imshow('blue1',blue)
cv.imshow('red1',red)
cv.imshow('green1',green)

cv.imshow('blue',b)
cv.imshow('red',r)
cv.imshow('green',g)

print(img.shape)
print(b.shape)
print(g.shape)
print(r.shape)

#merging image
merged = cv.merge([b,g,r])
cv.imshow('merged',merged)

cv.waitKey(5000)
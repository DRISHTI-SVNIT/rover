import cv2 as cv

img = cv.imread('photos/banswara.jpg')
cv.imshow('img',img) 

# grayscale
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("gray",gray)


#blur(image , kernel sixe(has to be odd number))
blur = cv.GaussianBlur(img,(3,3),cv.BORDER_DEFAULT)
cv.imshow("blur",blur)

#edge edges can be reduced by applying blur
canny = cv.Canny(img,125,175)
cv.imshow("canny",canny)

#dilating image
dilated = cv.dilate(canny,(3,3),iterations = 5)
cv.imshow("dilated",dilated)

cv.waitKey(3000)
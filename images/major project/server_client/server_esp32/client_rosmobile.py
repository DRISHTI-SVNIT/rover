import socket               
import time
import rospy
from geometry_msgs.msg import Twist
sock = socket.socket()
host = "192.168.210.165" #ESP32 IP in local network
port = 6677             #ESP32 Server Port  
sock.connect((host, port))  
x1,x2=0,0
def callback(data):
    print('HELLO')
    rospy.loginfo("%f %f %f %f %f", data.linear.x, data.linear.y,data.linear.z, data.angular.x, data.angular.y)
    #pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    y1 = data.linear.x #front
    y2 = data.linear.y #left
    x1='a'+str(180*y1)
    x2='b'+str(180*y2)
    x =x1+x2
    print(x)
    sock.send(x.encode())
    time.sleep(0.1)
def listener():
    rospy.init_node('listener',anonymous=True)
    rospy.Subscriber('cmd_vel',Twist,callback)
    rospy.spin()
if __name__=='__main__':
    listener()

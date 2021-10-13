#!/usr/bin/env python

data = [
	[1,0,0,0,0,0],
	[0,1,0,1,1,1],
	[0,0,1,0,1,0],
	[1,1,0,0,1,0],
	[1,0,1,1,0,0],
	[1,0,0,0,0,1],
]

class island_map:
    w=0
    h=0
    keep = []
    
    def kp(self,x,y):
        self.keep[y*self.w+x] = data[x][y]
        return self.keep[y*self.w+x]
    
    def check_neighbors(self,x,y):
        t=self.kp(x,y)
        if t==1 and x>0:
            if self.keep[y*self.w+x]==0:
                self.check_neighbors(x-1,y)
        if t==1 and x<self.w-1:
            if self.keep[y*self.w+x+1]==0:
                self.check_neighbors(x+1,y)
        if t==1 and y>0:
            if self.keep[(y-1)*self.w+x]==0:
                self.check_neighbors(x,y-1)
        if t==1 and y<self.h-1:
            if self.keep[(y+1)*self.w+x]==0:
                self.check_neighbors(x,y+1)
        
    
    def run(self,data):
        self.w = len(data)
        self.h = len(data[0])
        for i in range(0,self.w*self.h):
            self.keep.append(0)
        j=0
        k=0
        for x in range(0,self.w):
            k=0;
            if self.kp(x,k):
                self.check_neighbors(x,k)
            k=self.h-1    
            if self.kp(x,k):
                self.check_neighbors(x,k)
        for y in range(1,self.h-1):
            j=0
            if self.kp(j,y):
                self.check_neighbors(x,k)
            j=self.w-1    
            if self.kp(j,y):
                self.check_neighbors(x,k)
                
            
    def __init__(self, data):
        self.run(data)
        
    def print_data(self):
        for x in range(len(data)):
            for y in range(len(data[0])):
                print(" " + str(data[x][y]),end='')
            print("")
            
    def print_keep(self):
        for x in range(0,self.w):
            for y in range(0,self.h):
                print(" " + str(self.keep[y*self.w+x]),end='')
            print("")

p = island_map(data)
p.print_data()
print()
p.print_keep()

#include <iostream>
#include <vector>


struct point{
    uint8_t d{0};
    uint8_t k{0};

    bool keep(){
        k = d;
        return k;
    }
};

struct imap{
    size_t w=0,h=0;
    std::vector<point> points;
    void set_size(size_t W,size_t H){
        w=W;h=H;
    }
    bool boarder(size_t x,size_t y){
        return (((x==0) | (x==w-1)) | ((y==0) | (y==h-1)));
    }
    void check_neighbors(size_t x, size_t y){
        uint8_t t=points[y*w+x].keep();
        //check left
        if(t&&x>0){
            if(points[y*w+x-1].k){
                check_neighbors(x-1,y);
            }
        }
        //check right
        if(t&&x<w-1){
            if(!points[y*w+x+1].k){
                check_neighbors(x+1,y);
            }
        }
        //check down
        if(t&&y<h-1){
            if(!points[(y+1)*w+x].k){
                check_neighbors(x,y+1);
            }
        }
        if(t&&y>0){
            if(!points[(y-1)*w+x].k){
                check_neighbors(x,y-1);
            }
        }
    }
    void run2(){
        size_t x=0,y=0;
        for (x=0;x<w;x++){
            y=0;
            if(points[y*w+x].keep()){
                check_neighbors(x,y);
            }
            y=h-1;
            if(points[y*w+x].keep()){
                check_neighbors(x,y);
            }
        }
        for(y=1;y<h-1;y++){
            x=0;
            if(points[y*w+x].keep()){
                check_neighbors(x,y);
            }
            x=w-1;
            if(points[y*w+x].keep()){
                check_neighbors(x,y);
            }
        }
    }
    void run(){
        for(size_t x=0;x<w;x++){
            for(size_t y=0;y<h;y++){
                if(boarder(x,y)?points[y*w+x].keep():0){
                    check_neighbors(x,y);
                }
            }
        }
    }
    void printd(){
        for(size_t x=0;x<w;x++){
            for(size_t y=0;y<h;y++){
                std::cout<<" "<<(int)points[y*w+x].d;
            }
            std::cout<<"\n";
        }
    }

    void printk(){
        for(size_t x=0;x<w;x++){
            for(size_t y=0;y<h;y++){
                std::cout<<" "<<(int)points[y*w+x].k;
            }
            std::cout<<"\n";
        }
    }
};


int main()
{
    uint8_t data[6][6] = {
	{1,0,0,0,0,0},
	{0,1,0,1,1,1},
	{0,0,1,0,1,0},
	{1,1,0,0,1,0},
	{1,0,1,1,0,0},
	{1,0,0,0,0,1},
    };
    imap m;
    m.w = sizeof(data[0]);
    m.h = sizeof(data)/m.w;
    for(size_t x=0;x<m.w;x++){
        for(size_t y=0;y<m.h;y++){
            point temp;
            temp.d = data[y][x];
            m.points.push_back(temp);
        }
    }
    m.printd();
    m.run2();
    std::cout<<"\n\n";
    m.printk();

    m.points.clear();
    return 0;
}

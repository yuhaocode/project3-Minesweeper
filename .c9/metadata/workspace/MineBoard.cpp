{"changed":true,"filter":false,"title":"MineBoard.cpp","tooltip":"/MineBoard.cpp","value":"#include <iostream>\n#include <string>\n#include <cstdlib>\n#include <ctime>\n#include <vector>\n#include \"MineBoard.h\"\nusing namespace std;\n\nMineBoard::MineBoard(int width,int height,int mines_n){\n    int i=0;\n    this->getMine=0;\n    this->n_mine_remain=width*height-mines_n;\n    this->width=width;\n    this->height=height;    \n    this->mines_n=mines_n;\n    srand((unsigned)time(NULL));\n    this->Board = new Node*[height];\n    for(;i<height;i++){\n        this->Board[i] = new Node[width];\n    }\n    i=0;\n    for(;i<mines_n;){\n        int oned_index=rand()%(height*width);\n        int X=oned_index/width;\n        int Y=oned_index%width;\n        if(!this->Board[X][Y].isMine()){\n            Board[X][Y].setMine();\n            i++;\n        }\n    }\n    i=0;\n    for(;i<height;i++){\n        int j=0;\n        \n        for(;j<width;j++){\n            this->setState(&(this->Board[i][j]),i,j);\n            \n        }\n    }\n}\n\nvoid MineBoard::reSet(){\n    int i=0;\n    this->getMine=0;\n    this->n_mine_remain=this->width*this->height-this->mines_n;\n    for(;i<this->height;i++){\n        int j=0;\n        for(;j<this->width;j++){\n            this->Board[i][j].reset();\n        }\n    }\n    i=0;\n    for(;i<mines_n;){\n        int oned_index=rand()%(height*width);\n        int X=oned_index/width;\n        int Y=oned_index%width;\n        if(!this->Board[X][Y].isMine()){\n            Board[X][Y].setMine();\n            i++;\n        }\n    }\n    i=0;\n    for(;i<height;i++){\n        int j=0;\n        for(;j<width;j++){\n            this->setState(&(this->Board[i][j]),i,j);\n        }\n    }\n}\n\nvoid MineBoard::setState(Node* n,int x,int y){\n    if(!n->isMine()){\n        \n        if(x>0&&y>0&&x<this->height-1&&y<this->width-1){\n            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==0&&y==0){\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==0&&y>0&&y<this->width-1){\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==0&&y==this->width-1){\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x>0&&x<this->height-1&&y==this->width-1){\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==this->height-1&&y==this->width-1){\n            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==this->height-1&&y>0&&y<this->width-1){\n            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(x==this->height-1&&y==0){\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n        }\n        else if(y==0&&x>0&&x<this->height-1){\n            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}\n            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}\n        }\n        else{}\n    }\n    else{}\n}\nvoid MineBoard::showBoard(){\n    int i=0;\n    for(;i<this->height;i++){\n        int j=0;\n        for(;j<this->width;j++){\n            if(this->Board[i][j].isCover()){\n                cout<<\"■\";\n            }\n            else{\n                if(this->Board[i][j].isMine()){\n                    cout<<\"*\";\n                }\n                else{\n                    if(this->Board[i][j].isSet()){\n                        cout<<\"□\";\n                    }\n                    else{\n                        cout<<this->Board[i][j].getState();\n                    }\n                }\n            }\n        }\n        cout<<endl;\n    }\n}\nvoid MineBoard::getCoordinate(){\n    cout<<\"Please enter an position you want to uncover(format:x y):\";\n    cin>>this->x>>this->y;\n}\nvoid MineBoard::applyChanges(){\n    if(this->Board[this->x][this->y].isCover()){\n        this->Board[this->x][this->y].setUncover();\n        if(this->Board[this->x][this->y].getState()==-1){\n            cout<<\"getMine\"<<endl;\n            this->getMine=1;  //lose game\n            int i=0;\n            for(;i<this->height;i++){\n                int j=0;\n                for(;j<this->width;j++){\n                    if(this->Board[i][j].isMine()){\n                        this->Board[i][j].setUncover();\n                    }\n                }\n            }\n        }\n        else{\n            \n            this->n_mine_remain--;\n            if(this->Board[this->x][this->y].getState()==0){\n                this->expandlist.push_back(make_pair(this->x,this->y));\n                expand(this->x,this->y);\n            }\n        }\n    }\n}\nvoid MineBoard::expandHelper(int x,int y){\n    if(!this->Board[x][y].isMine()&&this->Board[x][y].isCover()){\n        this->Board[x][y].setUncover();\n        this->n_mine_remain--;\n        if(this->Board[x][y].getState()==0){\n            this->expandlist.push_back(make_pair(x,y));\n        }\n    }\n}\nvoid MineBoard::expand(int x,int y){\n    if(x>0&&y>0&&x<this->height-1&&y<this->width-1){\n        expandHelper(x-1,y-1);\n        expandHelper(x-1,y);\n        expandHelper(x-1,y+1);\n        expandHelper(x,y-1);\n        expandHelper(x,y+1);\n        expandHelper(x+1,y-1);\n        expandHelper(x+1,y);\n        expandHelper(x+1,y+1);\n    }\n    else if(x==0&&y==0){\n        expandHelper(x,y+1);\n        expandHelper(x+1,y);\n        expandHelper(x+1,y+1);\n    }\n    else if(x==0&&y>0&&y<this->width-1){\n        expandHelper(x,y-1);\n        expandHelper(x,y+1);\n        expandHelper(x+1,y-1);\n        expandHelper(x+1,y);\n        expandHelper(x+1,y+1);\n    }\n    else if(x==0&&y==this->width-1){\n        expandHelper(x,y-1);\n        expandHelper(x+1,y-1);\n        expandHelper(x+1,y);\n    }\n    else if(x>0&&x<this->height-1&&y==this->width-1){\n        expandHelper(x-1,y-1);\n        expandHelper(x-1,y);\n        expandHelper(x,y-1);\n        expandHelper(x+1,y-1);\n        expandHelper(x+1,y);\n    }\n    else if(x==this->height-1&&y==this->width-1){\n        expandHelper(x-1,y-1);\n        expandHelper(x-1,y);\n        expandHelper(x,y-1);\n    }\n    else if(x==this->height-1&&y>0&&y<this->width-1){\n        expandHelper(x-1,y-1);\n        expandHelper(x-1,y);\n        expandHelper(x-1,y+1);\n        expandHelper(x,y-1);\n        expandHelper(x,y+1);\n    }\n    else if(x==this->height-1&&y==0){\n        expandHelper(x-1,y);\n        expandHelper(x-1,y+1);\n        expandHelper(x,y+1);\n    }\n    else if(y==0&&x>0&&x<this->height-1){\n        expandHelper(x-1,y);\n        expandHelper(x-1,y+1);\n        expandHelper(x,y+1);\n        expandHelper(x+1,y);\n        expandHelper(x+1,y+1);\n    }\n    else{}\n    while(this->expandlist.size()!=0){\n        this->expandlist.erase(this->expandlist.begin());\n        expand(this->expandlist[0].first,this->expandlist[0].second);\n        \n    }\n}\n\nbool MineBoard::isfailure(){\n    return this->getMine==1;\n}\nbool MineBoard::isWin(){\n    return this->n_mine_remain==0;\n}\nMineBoard::~MineBoard(){\n    int i=0;\n    for(;i<height;i++){\n        delete [] this->Board[i];\n    }\n}\n","undoManager":{"mark":-2,"position":0,"stack":[[{"start":{"row":13,"column":24},"end":{"row":13,"column":28},"action":"insert","lines":["    "],"id":5133}]]},"ace":{"folds":[],"scrolltop":3120,"scrollleft":0,"selection":{"start":{"row":13,"column":28},"end":{"row":13,"column":28},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":194,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1476644646312}
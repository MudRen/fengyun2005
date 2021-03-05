// 把绝对左边转换成相对坐标
// 用法：convertcoor XXX x,y,z
// 其中XXX是要转换的目录，比如/d/fy/或者/d/chenxiang/ 记住最后一个/
// x,y,z是这个区域的中心点原来的绝对坐标，比如fy就是0,0,0
// 我没有动原来的文件，而给新转换出来的文件取名.cto(好像不是那个cto，而是to到的意思:)))
// 这个。。。 最好只转换一次，不然就麻烦大了。
// 以后我们计算坐标关系的时候，就需要用（区域坐标+相对坐标）而得到绝对坐标
// convertcoor.c

#include <ansi.h>
inherit F_CLEAN_UP;

int xcenter,ycenter,zcenter;
int do_convert(string arg);
int do_changecoor(string tofile,string line);

int main(object me,string arg)
//arg should be like this: "/d/fy/ 15,4,3" like this
{
    string *files;
    string dir;
    int i;
    int size;
    set_eval_limit(1); 
    seteuid(getuid());
    
    return notify_fail("
此命令用于转换相对坐标，破坏性极大，
风云4.0已完成此项工作，如果需要使用此命令请阅读修改此文件后执行。\n");

    sscanf(arg,"%s %d,%d,%d",dir,xcenter,ycenter,zcenter);    
    
    files= get_dir(dir);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-2)..size]==".c")
        {
            do_convert(dir+files[i]);
        }
    }
    return 1;
}

int do_convert(string arg)
{
    
    string tofile;
    string templine;
    int i;
        
    printf("now is convert file:%s\n",arg);    
    templine="";
    tofile=sprintf("%s%s",arg,"to");
    //log_file("static/convertcoor",arg+"\n");
    
    i=1; 
          
    do
    {           
        if( templine=efun::read_file(arg,i,1) )
        {
            do_changecoor(tofile,templine);
        }        
        else break;        
        i++;
    }while (1);
    return 1;
}

int do_changecoor(string tofile,string line)
{
    string x,y,z;
    string line2;
    int ix,iy,iz;
    int i;    
    
    //去掉table键;
    line2=replace_string(line,"\t","");
    //去掉空格
    line2=replace_string(line2," ","");    
    
    
    x="set(\"coor/x\",";
    y="set(\"coor/y\",";
    z="set(\"coor/z\",";
    //is it x?
    if(strsrch(line2,x,1)!=-1)
    {
        sscanf(line2,x+"%d);",ix);                    
        line2=sprintf("\t%s%d);\n",x,ix-xcenter);
        line=line2;
    }
    //is it y?
    if(strsrch(line2,y,1)!=-1)
    {
        sscanf(line2,y+"%d);",iy);        
        line2=sprintf("\t%s%d);\n",y,iy-ycenter);
        line=line2;
    }

    //is it z
    if(strsrch(line2,z,1)!=-1)
    {
        sscanf(line2,z+"%d);",iz);        
        line2=sprintf("\t%s%d);\n",z,iz-zcenter);
        line=line2;
    }    
    efun::write_file(tofile,line,0);
}

//  标准的帮派房间  /system/std/room/vroom.c                              //
//************************************************************************//
//  Edit by lala, on March 7, 1998                                        //
//  modified : 98-10-02 by nerd.                                          //
//  from /d/place/player/newroom.c                                        //
//  Last modified: 24-04-2002 by akuma.                                   //
//  add reset to it                                                       //
//  Last modified: 25-04-2002 by akuma.                                   //
//  announce: this file is not a real "room", it must be "compile_file"d  //
//  by master_ob's compile_file,so as to be got the file name by something//
//  we want. And,it is VIRTUAL_D who really does it :))                   //
//************************************************************************//

#include <ansi.h>
#define SIZE 9
#define VOBJ "/std/npc/vnpc"
inherit ROOM;

int save_me();// here we should add a interface to change some config of file
int restore_me(string file);// sure,we must resore some config that we want
int set_exits(string file);// we should create the virtual room's exits automatically
void clone_obj(string line,string datafile, string file);
void reset();
// and ,maybe we need reset() 

void create()
{
     
    set( "not_startroom",   1 );            //不是可以存储的地点。
    set( "short", "平地" );
    set( "long" , "这里是一片平地。\n");    
    set( "no_clean_up", 0 );
    setup();
}

int set_exits(string file)
{
    string x,y;    
    //我自己的坐标
    string xy;    
        
    xy=file[sizeof(file)-3..];        
    file=(string) file[0..sizeof(file)-4];
    // here is "5" because we get x,x as to name of room    
    sscanf(xy,"%s_%s",x,y);
    
    //east
    if(to_int(x)<SIZE)
        set("exits/east",sprintf("%s%d_%s",file,to_int(x)+1,y) );
    //west
    if(to_int(x)>1)
        set("exits/west",sprintf("%s%d_%s",file,to_int(x)-1,y) );
    //south
    if(to_int(y)<SIZE)
        set("exits/south",sprintf("%s%s_%d",file,x,to_int(y)+1) );
    //north
    if(to_int(y)>1)
        set("exits/north",sprintf("%s%s_%d",file,x,to_int(y)-1) );        
}

// 关于restore和 save
// 应该有short long roomtype npc
// exits就不管了吧 :))

int restore_me( string file )
{
    int i = 0;
    string * lines;
    string datafile;
    
    sscanf(file,"/d/place/domain/%s",file);       
    datafile = DATA_DIR+"domain/"+file[0..0]+"/"+file;
    
    if ( file_size(datafile) <= 0 )
        return 1;
    lines = explode( read_file(datafile), "\n" );
    while ( i < sizeof(lines) )
    {
        mixed key, val;
        string line = lines[i];
        if (line[0] == ' ')
            return 0;
        if (sscanf(line, "%s=%s", key, val)==2)
        {
            //是obj吗？
            if (key =="objects")
            {
                //start to clone object
                while ( line != "end" && i < sizeof(lines) - 1 )
                {
                    i++;
                    line = lines[i];
                    if ( line[0] != ' ' )
                        continue;
                    clone_obj( line , datafile ,file);
                }
            }            
            else
            {
                if (val == "")
                {
                    while ( line != "end" && i < sizeof(lines) - 1 )
                    {
                        i++;
                        line = lines[i];
                        if ( line[0] != ' ' )
                            continue;
                        val += line[1..] + "\n";
                    }
                }
                set(key,val);            
           }                
        }
        i++;
    }    
    set("outdoors", "domain_"+file[0..sizeof(file)-5]);    
    return 1;
}


int save_me()
{
    return 1;
}

string query_save_file()
{   
/*    string temp = file_name(this_object());
    sscanf(temp,"/d/place/domain/%s",temp);
    return DATA_DIR+"domain/"+file[0..0]+"/"+file;
*/
}

void clone_obj(string line,string datafile,string file)
{
    string name;
    string count;
    int i;
    object obj;
    
    sscanf(line," %s:%s",name,count);
    //我们应该判断npc还是obj吧:))
    //现在只写一个测试的npc        
    for(i=0;i<to_int(count);i++)
    {
        obj=new(VOBJ);//需要virtual object吗？
        obj->restore_me();
        obj->set("born_from","/d/place/domain/"+file);//这里不能用file_name
        obj->move(this_object());
    }
}

void reset()
{
    object *inv;
    int i;
    inv = all_inventory();
    for(i=sizeof(inv)-1; i>=0; i--)
	{
        if(inv[i]->is_character()) 
        {
            if( (string) inv[i]->query("born_from") == (string) file_name() )
                destruct(inv[i]);
            continue;
        }
	    if(inv[i]->query("no_get")) continue;
	    if(inv[i]->is_corpse()) continue;
        destruct(inv[i]);
	}
    restore_me(file_name());
    //没有这么简单吧，我们还要判断地上的东西是不是要去掉，
    //是本地的npc就dest掉，然后再弄个新的回来
    //这样是不是有问题呢？，但是这样最简单
    //懒得写那么复杂的reset了。
}

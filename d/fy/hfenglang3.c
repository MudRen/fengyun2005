
inherit DOOR_ROOM;
#include <room.h>

void create()
{
    set("short", "浣凰长廊");
    set("long", @LONG
这里是给到这儿的小姐们更衣入浴的，地上是五光十色的彩带和香味扑鼻的花
瓣，昂贵的衣裳满地都是，透过蒙蒙水雾，可以看到白腻的身躯，修长的大腿，坚
挺的胸膛，和乌黑的长发。。。。。。
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang2",
	"south" : __DIR__"hfengpool",
      ]));
    set("objects", ([
	__DIR__"npc/smileboy": 1,
      ]) );
    set("coor/x",-80);
    set("coor/y",-255);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("south","door","檀木门", "north", DOOR_CLOSED);

}


int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    int weartowel=0;
    
    if( dir == "south" && ob=present("jin tong", this_object()) )
    {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{    
		    if( (string)(inv[i]->query("id")) == "white towel" ){
					withtowel = 1;
					if (inv[i]->query("equipped"))
						weartowel = 1;
			}
		}
		if( !withtowel)
	    	return notify_fail("金童向你笑道：没有白毛巾怎么洗？\n");
    	if (!weartowel)
			return notify_fail("金童向你笑道：还是围上毛巾再进去吧，不要吓到别人．\n");
	}
	
    if( dir == "north" && ob=present("jin tong", this_object()))
    {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
		    if( (string)(inv[i]->query("id")) == "white towel")
		    {
			tell_object(me,ob->name()+"笑咪咪的将你身上湿的"+
			  inv[i]->name()+"拿了回去．\n\n\n");	
			destruct(inv[i]);
		    }
		}
    }
    return ::valid_leave(me,dir);
}

inherit DOOR_ROOM;
#include <room.h>

void create()
{
  	set("short","无眠阁");
  	set("long",@LONG
楼上便是兴国禅寺的高僧们研读经书的地方，这儿灯明几净，几个新来的小和
尚忙忙碌碌地收拾着，他们大多是附近人家的子弟，慕着禅寺的名声前来投单，兴
国大师把他们分派到这里打扫，据说可以磨练掉凡世的浮躁之气。
LONG
  );
  	set("exits",([
         	"south":__DIR__"yezhang",
         	"up":	__DIR__"cjg",
               ]));
        set("objects", ([
                __DIR__"npc/bonze_j1" : 1,
                __DIR__"npc/bonze_j2" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	create_door("south","door","石门","north",DOOR_CLOSED);
}


/*
void reset() {
	string *item= ({"book1","book2","book3","book4","book5" });
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(__DIR__"obj/"+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


*/	
	
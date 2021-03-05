inherit DOOR_ROOM;
#include <room.h>

void create()
{
  	set("short","藏经阁");
  	set("long",@LONG
这儿到处是书，无穷无尽的经书，四壁和中央都是连着屋顶的红木书架，屋子
中间是四五个蒲团，几个白眉白发的老僧半闭着眼似醒非醒地在打坐，除此以外，
便只有几付砚台，几支宣毫，散放在书案上。
LONG
  );
  	set("exits",([
         	"down":	__DIR__"mishi1",
               ]));
        set("objects", ([
                __DIR__"npc/bonze_h1" : 1,
                __DIR__"npc/bonze_h2" : 1,
                __DIR__"npc/bonze_h3" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	
}



void reset() {
	string *item= ({"force_75","force_75a","force_75b","force_75c","force_75d" });
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(BOOKS+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


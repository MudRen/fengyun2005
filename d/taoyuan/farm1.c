inherit __DIR__"no_killing_place";
void create()
{
        set("short", "农家");
        set("long", @LONG
这是一户很简朴的农家，土坯垒成的墙冬暖夏凉，茅草盖顶，虽然简陋却足以
遮风僻雨。门敞开着，屋内陈设十分简单，而且静悄悄的，主人好象出去做活了。
墙上挂着一些常用的农具，泥痕还很新鲜。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"nongjia",
	]) );

   	set("objects", ([
    	__DIR__"obj/wall": 1,
   	]) );

	set("no_magic", 1);
	set("coor/x",5);
	set("coor/y",10);
	set("coor/z",0);

	setup();
}


void reset()
{
	object *inv;
        object item1, item2, item3, wall;
        int hook,raincoat,liandao,i; 
        ::reset();
        wall = present("wall", this_object());
        inv = all_inventory(wall);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("id")=="hook") hook=1;
        	if (inv[i]->query("id")=="raincoat") raincoat=1;
        	if (inv[i]->query("id")=="liandao") liandao=1;
        }
        if (!hook) {
        	item1 = new(__DIR__"obj/hook");
        	item1->move(wall);
        	}
        if (!raincoat) {
        	item2 = new(__DIR__"obj/raincoat");
        	item2->move(wall);
        	}
        if (!liandao) {
        	item3 = new(__DIR__"obj/liandao");
        	item3->move(wall);
        	}
}



inherit ROOM;

void create()
{
        set("short", "独木危桥");
        set("long", @LONG
这是一条宽约七寸的独木桥，天风凛冽，吹的人衣襟头发齐飞，只要一不留神，
稍一失足，立刻便要粉身碎骨。两崖相隔，约有五十余丈，往下看，峭壁如刀削，
云卷雾涌，深不见底，投块石子下去，也听不到回声！
LONG
        );
        set("exits", ([ 
 	 	"east" : __DIR__"intersection",
  		"west" : __DIR__"entrance",
		]));
        set("outdoors", "palace");

	set("coor/x",-100);
	set("coor/y",100);
	set("coor/z",10);
	setup();
}



int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int chance;
	
	
	if (me->query("timer/insurance") + 259200 > time())
		return 1;
	
	if( userp(me))
	{
		chance = (me->query("kar")>20)? me->query("kar"): 20;
			
		switch(random(chance)){
			case 0:
				message_vision("$N脚下一滑，在独木桥上晃了晃．．\n",me);
				return notify_fail("还好，没掉下去！\n");
				break;
			case 1:
				inv = all_inventory(me);
				if(sizeof(inv)>=1)	
				{
					ob = inv[random(sizeof(inv))];
	                if (ob->query("no_drop") || ob->query("owner")
	                	|| ob->query_autoload()) break;
					message_vision(ob->name()+"从$N身上滑了出来，落入万丈深渊．\n",me);
					destruct(ob);
				}
				tell_object(me,"你在独木桥上前仰后合地晃着．．．\n");
				return 1;
				break;
			default:
				return 1;
				break;
				}
		return 1;
	}
	
	return 1;
}


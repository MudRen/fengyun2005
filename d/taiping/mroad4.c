
inherit ROOM;
void create()
{
        set("short", "小街");
        set("long", @LONG
再往镇里走，两旁的店铺多了起来，西侧的“平安老店”既是个客栈，也是家
酒铺，东侧的屋子里传来丁丁当当打铁的声音。街的两旁种的仍然是枫树。秋风一
吹到，叶就绯红了起来，灿烂如朝露，如秋容的胭脂，把一个普普通通的小镇打扮
成了个娇丽的佳人。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"laodian",
		"east" : __DIR__"tiepu",
		"south": __DIR__"mroad45",
		"north": __DIR__"mroad3",
	]));
        set("outdoors", "taiping");
	
	if (random(3)) {
		set("objects", ([
	        	__DIR__"npc/drunk" : 2,
	        ]) );
	} else {
		set("objects", ([
	        	__DIR__"npc/fakedrunk": 2,
	        ]) );
	}
	
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}

void reset(){
	if (random(4)) {
		set("objects", ([
	        	__DIR__"npc/drunk" : 2,
	        ]) );
	} else {
		set("objects", ([
	        	__DIR__"npc/fakedrunk": 2,
	        ]) );
	}
	::reset();	
}

void init(){	
		object me, *inv;
		int num, i;
		
		me = this_player();
		
		num = sizeof(me->query("marks/parrot"));
		if ( REWARD_D->riddle_check(me,"喋血鹦鹉")==6 && num >=6
				&& !me->query("marks/parrot/遇刺") ) {
				inv=all_inventory(this_object());
					for (i=0;i<sizeof(inv);i++){
						if (inv[i]->query("marks/parrot_killer")){
							message_vision("$N对着$n叫到：明年今天就是你的忌日！！\n",inv[i],me);
							inv[i]->kill_ob(me);
							me->kill_ob(inv[i]);
						}
					}
				}
		return;
	
}	
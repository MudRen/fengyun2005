/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "艾丁湖");
        set("long", @LONG
艾丁湖，北有博格达山，西有喀拉乌成山，南有觉洛塔格山，东南有库姆塔格
山。意为月光湖。因湖大部分是皱褶如波的干涸湖底，触目皆是银白晶莹的[37m盐巴[32m，
在阳光下闪闪发光，酷似寒夜睛空的月光，故名艾丁湖。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/saltboss" : 1,
                        ]) );
        set("item_desc", ([
	           "盐巴": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
	           "yanba": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
	           "salt rock": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
	           "salt": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
        ]));
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
		set("coor/x",50);
		set("coor/y",-60);
		set("coor/z",10);
		setup();
}


void dig_notify()
{
     object me, salt;
     me = this_player();     
          
     message_vision("$N在湖底开始忙乱地挖掘起来。\n",me);
     
    if (!me->query_temp("marks/xj_noticed_salt")) {
    	tell_object(me,"漫无目的地挖了半天，运气真不好，什么都没有找到。\n");
    	return;
    }
     
     if(query("already")) {
     	tell_object(me,"能挖动的盐巴都已经被挖完了。\n");
     	return ;
     }
     
     message_vision("锵．．得一声，再看地上的盐巴被$N砸下一小块。\n", me);
     salt = present("salt rock", this_object());
     if(!objectp(salt)) {
        salt = new(__DIR__"obj/salt");
        salt->move(this_object());
     }
	set("already",1);
}


void reset(){
	::reset();
	if (!random(20))
		set("already",0);
}

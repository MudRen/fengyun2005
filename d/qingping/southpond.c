//XXDER
inherit ROOM;
void create()
{
        set("short", "池塘");
        set("long", @LONG
这是池塘的南端，站在这里你可以清楚的看到小桥的全貌。小桥不知是用什么
石头砌成，通体洁白无瑕，倒映在碧绿的水中，加上睡莲，垂柳，奇石，岸边的小
花，还有蜿蜒的小路，构成了一幅美丽的图画。墙边窗下，几株芭蕉正开出鲜艳的
花朵，芭蕉旁还摆了一个小小的竹榻。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "east" : __DIR__"southpond1",
   "northwest" : __DIR__"pond",
   ]));

   set("objects", ([
      __DIR__"obj/bamboobed" : 1,
      __DIR__"obj/ground" : 1,
      __DIR__"npc/baoyu": 1,
   ]) );

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
   set("outdoors", "qingping");
}


void reset()
{
   object *inv;
   object item1, ob;
   ::reset();

   ob = present("bamboo bed", this_object());
   inv = all_inventory(ob);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/pillow");
      item1->move(ob);
   }
   ob = present("ground", this_object());
   inv = all_inventory(ob);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/qiuyin");
      item1->move(ob);
   }

}


// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "膳房");
        set("long", @LONG
膳房里面干净异常，居然没有一丝烟尘，菜色也是分外的精致，膳房中间是一
张大桌子，几个青衣小鬟一边低语一边准备着菜肴，没想到江湖人畏之如虎的白水
宫女居然这么的活泼可爱，可见江湖传言未必尽实。
LONG
        );
   set("exits", ([ 
      "west" : __DIR__"gong",
   ]));
   set("objects", ([
      __DIR__"obj/table": 1,
      __DIR__"npc/qinggirl": 3,
   ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void reset()
{
   object *inv;
   object item, table;
   ::reset();

   table = present("table", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item = new(__DIR__"obj/tangbao");
      item->move(table);
      item = new(__DIR__"obj/douya");
      item->move(table);
   }
}



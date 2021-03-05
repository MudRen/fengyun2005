//XXDER
inherit ROOM; 
void create()
{
   set("short", "小厅");
   set("long", @LONG
这是一个小巧而精致的楼房，楼下布置的象个小客厅兼书房。房中间是一个小
红木八仙桌，旁边摆了四把椅子，靠窗是一张书桌，上面摆满了笔墨砚台，书桌角
上放了几本书。书桌旁边是一书架，架上摆满了各式各样的书。站在书桌前向窗外
望去，可以看到窗外的芭蕉和池塘的一角。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"garden",
      "up" : __DIR__"bedroom3",
   ]));

   set("objects", ([
      __DIR__"npc/laner": 1,
      __DIR__"obj/desk": 1,
   ]) );

   set("item_desc", ([
      "window": "向窗外望去，只见小桥流水，绿叶红花，你被这美丽的景色深深吸引了。\n",
      "窗户": "向窗外望去，只见小桥流水，绿叶红花，你被这美丽的景色深深吸引了。\n",
   ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
}

void init()
{
   add_action("do_look", "look");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if(!arg || (arg != "bajiao" && arg != "芭蕉")) 
   return 0;
   me->set_temp("marks/bajiao",1);
   tell_object(me, "窗外的芭蕉开的正热闹，你注意到芭蕉下的土似乎被松过。\n");
   return 1;
   
}

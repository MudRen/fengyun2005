inherit ROOM;
void create()
{
        set("short", "大厅");
        set("long", @LONG
厅很大，布置的极有气派，正对厅门是一面屏风，屏风上画的是一片云雾缭绕
的山峰，十分险恶，看上去有些象华山，可又比华山多了些秀美，就连房子的主人
白三空也不知道画上所描何处。屏风前是一把高大的紫檀木椅，上面有用紫绒布做
的靠垫，两边墙上挂满了名家书画，除了这些，大厅里没有别的摆设。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wuchang1",
  "east" : __DIR__"aroad",
  "north" : __DIR__"northting",
  "south" : __DIR__"southting",
]));

   set("objects", ([
      __DIR__"npc/gongsun": 1,
   ]) );
	set("coor/x",-50);
	set("coor/y",0);
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

   if (!arg || (arg != "屏风" && arg != "pingfeng")) return 0;
   tell_object(me, "只见那群山之间，云雾缭绕之中似乎有个白色的湖泊，在湖的东北方
似乎有一淡淡的印痕，不仔细是觉对发现不了的。 \n");
   me->set_temp("marks/foundgate", 1);
   return 1;
}

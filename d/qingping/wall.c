//XXDER
inherit ROOM;
void create()
{
        set("short", "院墙");
        set("long", @LONG
院墙很高，旁边是一颗高大的槐树，茂密的树枝遮挡了你的视线，你看不清院
内的情况。院子外面是一片松林，这一片松林也阻断了你的视线，松树下是荒芜的
野草和乱石，可见这里很少有人走动。
LONG
        );
   set("outdoors", "qingping");
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",10);
   setup();
}

void init()
{
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;

   me = this_player();
   if(!arg || arg != "down" ) return 0;
   message_vision("$N纵身跃起，轻飘飘地落到了院内地上。\n\n", me);
   room = find_object(__DIR__"garden"); 
   if(!objectp(room)) room=load_object(__DIR__"garden");
   me->move(room);
   message("vision", me->name()+"似乎从天而降，轻飘飘地落到了地上。\n", environment(me), me); 
   return 1;
}

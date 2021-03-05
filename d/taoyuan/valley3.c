inherit ROOM;
void create()
{
        set("short", "山谷");
        set("long", @LONG
树林到了此处逐渐变得稀疏起来，眼前赫然出现一座千层叠翠、万里点苍的山
峰，围成一处幽谷，中有一泓清潭，泉水从峰间奔流而下，喷珠泄玉，直入清潭。
几只白尾巴的野兔，正在潭边悠闲的喝水。此处空气清凉湿润，沁人心肺，四周却
看不见任何明显的出路，看来，你只好四处转转看了。
LONG
        );
        set("item_desc", ([
           "清潭":  "清潭明澈见底，不时的有小鱼越出水面。\n",
           "pond":  "清潭明澈见底，不时的有小鱼越出水面。\n",
        ]));
        set("exits", ([ /* sizeof() == 4 */
]));
        set("outdoors","taoyuan");
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_around", "around");
}

int do_around(string arg)
{
   object me, room;
   int i;
   
   string *rooms = ({"valley", "valley1", "valley2", "valley3"});
   i = random(4);
   me = this_player();
   tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n");
   room = find_object(__DIR__ + rooms[i]);
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
   me->move(room);

   return 1;
}


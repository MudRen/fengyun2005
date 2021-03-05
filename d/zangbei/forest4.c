inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "密林");
        set("long", @LONG
密林里一片漆黑，绝无树叶触擦的声音，也绝无夏夜的那种半明半昧的清光。
高大的树干狰狞张舞。枯萎丛杂的矮树在林边隙地上瑟瑟作声。长大的野草在寒风
中鳗鲡似地蠕蠕游动。蓁莽屈曲招展，有如伸出了长臂，张爪攫人。
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest3",
		"southeast":	__DIR__"v_gate",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"tree": "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"树干":  "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"树":   "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"矮树": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。\n",
		"bush": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。\n",
		"vine": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。\n",
	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1560);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	set("bandit",2);
	setup();
}


void init(){

	add_action("do_climb","climb");
}

void reset()
{
	object killer;
        ::reset();
        set("bandit",2);
        killer = present("bandit", this_object());
        if (killer && !userp(killer))
        if (!killer->is_fighting()) {
        	destruct(killer);
	}
}


int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="树")) 
		return 0;
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	room=find_object(__DIR__"tree1");
	if (!objectp(room)) room=load_object(__DIR__"tree1");
	message_vision("$N手脚并用，麻利地向大树上爬去。\n",me);
        tell_room(room, this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(room);
        return 1;
}


int valid_leave(object obj, string dir){
	object another;
	seteuid(getuid());
	
	if(dir == "southeast"){
		if (present("bandit", this_object()))
		{
			another = present("bandit", this_object());
			return notify_fail(another->name()+"闪身挡住了你的路。\n");
		} else if (random(10)>5 && query("bandit")>0) {
			another = new(__DIR__"npc/bandit1");
			another->move(environment(obj));
			message_vision(HIB"树叶哗啦啦一阵乱响，跳下一个人来！\n"NOR, obj);	
			add("bandit",-1);
			return notify_fail(another->name()+"喝道，什么人敢私闯我龙虎寨，拿命来！\n");
		}
	}	
	return 1;
}
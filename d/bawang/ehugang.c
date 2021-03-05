#include <ansi.h>
inherit ROOM;
#define LOWER_LIMIT 150000
#define DUMP_PLACE  "/d/bawang/trap.c"

void create()
{
	set("short", "饿虎岗正门");

	set("long", @LONG
两棵参天大树形成个天然的寨门，树上龙飞凤舞刻着三个大字：
					
                  饿 虎 岗 

蓝天白云，远山青翠，据说大江以北、黄河两岸，黑道上所有可怕的人物，几乎已
全部囊集在饿虎岗。两个彪形大汉拿着大砍刀守着寨门。  
LONG);

	set("type","road");
	set("exits",([
        "northdown":__DIR__"shanlu2",
		"southup":__DIR__"shanlu3",
	]) );

        set("objects", ([
        	__DIR__"npc/big_bandit": 1,
        	__DIR__"npc/lit_bandit": 1,
        ]));

	set("no_lu_letter",1);
	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	int wearing;
	object ob;
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if((string)inv[i]->query("name") == "脏布衣"&& (int)inv[i]->query("equipped") )
		{
			wearing = 1;
		}
	}
	
	if(userp(me) && !me->query_temp("marks/keychain_ehg"))
	{
		if(dir == "southup" && ob=present("da louluo", this_object()))
		{
			if((string)me->name()!="老山东" )
				return notify_fail("大喽罗有气无力瞪着你道：去去去，真是吃饱了撑得，跑饿虎岗\n来转什么，当心饿大虫一口吞了你！\n");
			else if( !wearing)
			{
				return notify_fail("大喽罗盯着你上看看，下瞅瞅，大骂道：好啊！戴个面具就以为能蒙老子了！\n");
			}
			else if( !me->query_temp("yuehu") )
			{
				return notify_fail("大喽罗咽了咽口水笑道：老山东，又给咱们寨主送烧鸡？不留下两只，\n对兄弟们可交代不过去呦......\n");
			}
			else
				return 1;		
		}
		else if (dir == "southup" && ob=present("xiao louluo", this_object()))
		{
			if((string)me->name()!="老山东" )
				return notify_fail("小喽罗有气无力瞪着你道：去去去，真是吃饱了撑得，跑饿虎岗\n来转什么，当心饿大虫一口吞了你！\n");
			else if( !wearing)
			{
				return notify_fail("小喽罗盯着你上看看，下瞅瞅，大骂道：好啊！戴个面具就以为能蒙老子了！\n");
			}
			else if( !me->query_temp("yuehu") )
			{
				return notify_fail("小喽罗咽了咽口水笑道：老山东，又给咱们寨主送烧鸡？不留下两只，\n对兄弟们可交代不过去呦......\n");
			}
			else
				return 1;		
		}
		return 1;
	}
	else 
		return 1;
}

void init() 
{ 
	add_action("do_kill", "kill"); 
}

int do_kill(string arg)
{ 
	object me;
	object room;
	object dalouluo, xiaolouluo;
	me = this_player();
	if(!arg) return 0;
	if( arg != "da louluo" && arg != "xiao louluo" && arg != "louluo") return 0;
	dalouluo = present("da louluo", this_object());
	xiaolouluo = present("xiao louluo", this_object());
	if(!objectp(dalouluo)) return 0;
	if(!objectp(xiaolouluo)) return 0;
	dalouluo->kill_ob(me);
	xiaolouluo->kill_ob(me);
	if( (int)me->query("combat_exp") <= LOWER_LIMIT)
	{
        	message_vision("小喽罗扯着嗓子高呼：有点子硬闯啊！快来人呀！ \n", me); 
		return 1;
	}
	else
	{
        	message_vision("小喽罗扯着嗓子叫了声：嘿呦，这点子够硬，风紧扯乎......外送大礼一份......\n", me); 
        	message_vision("大小喽罗们一猫腰，都闪在一旁幸灾乐祸看着你......\n",me);
        	message_vision(HIR "$N突然发现脚下悬空，身子猛地一沉，眼前顿时一黑......\n“唉呦！妈呀！”$N大叫一声，一个躲闪不及，“扑通”一声陷了下去.......\n"NOR,me);
		room = find_object(DUMP_PLACE);
		if(!room) room=load_object(DUMP_PLACE);
		if(room)  me->move(room);
        	message("vision", me->name()+"从上面只摔了下来，“呯！”地一声结结实实地摔在坑底。\n", environment(me), me);
		return 1;
   }
}

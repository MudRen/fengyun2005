inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "白石");
        set("long", @LONG
这是一块巨大的白色山石，大约可以容纳六七个人。石头的表面异常平滑，令
人惊奇的是石面上的几块[30m黑色印痕[32m，不知是天然而成，或是人为的痕迹。向下望，
可以看到碧蓝的湖水；向上望，只见上面云雾缭绕，不知还有多高才会到顶。
LONG
        );
    	set("item_desc", ([
        	"黑色印痕" : "好像是人的足印般大小，也许你可以试着踩一踩（step）。\n",
     	]));

		set("outdoors","fengyun");
		set("coor/x",-50);
		set("coor/y",60);
		set("coor/z",20);
		setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}

int do_step(string arg)
{
	object me= this_player();
	if(!arg || arg != "黑色印痕" )
		return notify_fail("你要踩什么？\n");
	message_vision(YEL"$N一脚踩在石面上的黑色印痕，只听到＂吱呀＂一声，
崖壁上裂开了一道门户！\n"NOR, this_player());
	set("exits/enter", __DIR__"holeopen2");
    REWARD_D->riddle_done(me,"巧过白石",10,1);
	if (QUESTS_D->verify_quest(me,"巧过白石"))
		QUESTS_D->special_reward(me,"巧过白石");
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("你要往上或下爬？\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n"NOR, me);
		message_vision(HIR "\n$N手上一个没抓稳，从危崖上掉了下去！\n"NOR, me);
		me->move(__DIR__"yadi");
                me->receive_damage("kee", 150);
                me->receive_damage("sen", 150);
                me->receive_damage("gin", 150);
		message_vision(HIR "\n$N从危崖上掉了下来，重重的摔在了地上！\n"NOR, me);
		me->set_temp("last_damage_from","于帝王谷坠崖身亡。\n");
		
	}
	else {
		message_vision(HIY "$N小心翼翼地向下爬去，身形慢慢被云雾遮掩。"NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}

int reset(){
	delete("exits/enter");
	::reset();
}
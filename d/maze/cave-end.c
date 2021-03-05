// silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绿血池");
	set("long", @LONG
屋子后方是一个一丈见方的池子，池中漂浮着尸骨，奇异的药草，尽是绿色的
液体，滚滚冒着血腥之气，池旁一排围着十几个铜鼎，鼎内香烟缭绕，屋内灰雾弥
漫这。就是炼制苍生乱的绿血池。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"cave-exit",

	]));
	set("objects", ([
                __DIR__"npc/cv-yecha1": 1,
                __DIR__"npc/cv-yecha2": 1,
                __DIR__"npc/cv-yecha3": 1,
                __DIR__"npc/cv-yecha4": 1,
        ]) );
	
	set("item_desc", ([
        	"绿血池":	"
一丈见方的绿血池，池中漂浮着尸骨和妖绿的药草。。。你可以将东西投掷（throw）进去。\n",
        	"pond":	"
一丈见方的绿血池，池中漂浮着尸骨和妖绿的药草。。。你可以将东西投掷（throw）进去。\n",
	]) );
	setup();
	
}


void	init(){
	add_action("do_throw","throw");
}


int	do_throw(string arg){
	object seed, me, *inv, item, guard;
	mapping data;
	me = this_player();
	if (!arg) 
		return notify_fail("你要投掷什么？\n");
	
	inv = all_inventory(this_object());
	foreach (object ob in inv) {
		if (ob->query("sq_guard")) {
			ob->kill_ob(me);
			return notify_fail(ob->name()+"啸叫一声，向你发动攻击。\n");
		}
	}
		
	inv = all_inventory(me);
	foreach (object ob in inv){
		if (ob->query("name")==arg || ob->query("id")==arg) {
			item = ob;
			break;
		}
	}
	if (!item)
		return notify_fail("你没有这件物品。\n");
	if( userp(item))
                return notify_fail("你不可烧活的东西．\n");
        if( item->query("owner")|| item->query("no_burn"))
                return notify_fail("这样东西不能烧。\n");
	
	if (query("burnt"))
			return notify_fail("绿血池已经被烧干了。\n");

	if (item->query("name")==RED"灵符火种"NOR) {
		message_vision(HIG"$N一甩手，把灵符火种投入池内，轰地一声，真火在血池中熊熊烧了起来。 \n"NOR,me);
		if (!REWARD_D->check_m_success(me,"智毁血池"))	
		{
			REWARD_D->riddle_done(me, "智毁血池",100, 1);
			data = ([
				"name":		"黄金塔：智毁血池",
				"target":	me,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		me->start_busy(8);
		set("burnt",1);
		call_out("burning",10, me);
		call_out("hint",60, me);
		destruct(item);
		return 1;
	}
	message_vision(HIG"$N一甩手，把"+item->name()+"投入池内，咕嘟一声，冒起一丝绿烟，便溶得无影无踪了。\n"NOR,me);
	destruct(item);
	return 1;
}

// 这个jade is bonus, not required to continue riddle.
//	Here we will allow 那些已经拿到宝甲的人看到jade,没宝甲没有意义.

int burning(object me){
	
	object pill;
	message_vision(RED"火势逐渐小了下去，绿血池中的血水，尸骨，药草终于全被烧得一干二净。 \n"NOR,me);
/*	if (me->query("maze/宝甲")) {
		message_vision(RED"火势燃尽，绿血池空空如也，却多了一颗闪烁着奇异的光辉的碧血石。\n"NOR,me);
		pill = new(__DIR__"obj/jade_1");
		if (pill) { 
			pill->move(this_object());
			pill->set("owner",me);
		}
	}*/
	return 1;
}

// This hint is also not required to continue.
int hint(object me){
	tell_object(me,GRN"
你忽觉胸口隐隐发涨，仔细打量，竟发现双手布满了诡异的绿线。你顿生恐
怖之心，莫非染上了苍生乱？还是赶快找丁乘风问个清楚吧。 \n"NOR);
	return 1;
}


void reset(){
	set("burnt",0);
	::reset();
}
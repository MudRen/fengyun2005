#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "顶楼");
    set("long", @LONG

	[45m[1;33m武	学	重	地	闲	人	莫	入[2;37;0m

下面贴着一张告示（[37mｓｉｇｎ[32m）

LONG
    );
    
	set("no_fight",1);
	set("no_fly",1);
	set("exits", ([
	"down" : __DIR__"jssju2",
      ]));

     set("item_desc", ([
		"sign": @TEXT
[0;1;37m──────────────────────────────────[0m

为鼓励广大武林新秀多学武艺、多作尝试，本处提供业务可将所学到的武学
技能与所花费的潜能点融会贯通，自由交换。

本处交易力求简明，在这里你可以干三件事：
１．用check命令检查各个技能能返回多少潜能，格式为：check 技能英文名
２．用pay命令交付手续费，花费的黄金等于你等级。交费后，离开（包括走
    开或者断线）前可以任意使用refund命令，无需进一步交费。
３．交费后，可使用refund命令，格式为：refund 技能英文名

注意事项：1。离开以后，需要重新交费。
          2。返回会把你在当前技能上学习，研究所花的潜能完全返回


[0;1;37m──────────────────────────────────[0m
TEXT
      ]) );

    set("objects", ([
	
    ]) );
	
    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",30);
    set("map","fynorth");
    setup();
}

void init(){
	
	add_action("do_pay","pay");
	add_action("do_check","check");
	add_action("do_refund","refund");
	add_action("do_answer","answer");
}


int do_check(string arg){
	object me;
	int pot, level,i;
	string *limit;
	
	me = this_player();
		
	if (!arg)	return notify_fail("你要查询你学过的那一项技能？\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("该项技能不存在或者你没有学过该项技能。\n");
	
	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"你已经掌握了"+level+"级"+ SKILL_D(arg)->name()+"（"+arg+"）\n"NOR);	
	tell_object(me,HIR"你在该技能上共花费了"+pot+"点潜能，\n"NOR);
	
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("该技能涉及到人物属性变化，无法回复成潜能。\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			tell_object(me,"该技能为"+SKILL_D(limit[i])->name()+"（"+limit[i]+"）的基础：你拥有"+level+"级。\n");
		}
		tell_object(me,HIW"唯有将所有关联武功先行洗去后才能洗去此技能。\n"NOR);
	}
	else
		tell_object(me,HIR"如果你选择 refund ，这将是你所能够拿回的潜能点数。\n"NOR);
		
	return 1;
		
}


int do_pay(){
	
	object me;
	int level;
	
	me = this_player();
	
	if (me->query_temp("marks/refund_enable"))
		return notify_fail("你已经付过手续费了，请使用refund命令改变技能。\n");
		
	level = F_LEVEL->get_level(me->query("combat_exp"));
	tell_object(me,"refund 需要黄金" + level + "两，自动从钱庄转账，你是否愿意？（answer yes/no）\n");
	
	me->set_temp("marks/jssju3_pay",1);
	
	return 1;
}


int do_answer(string arg){
	
	object me;
	int level;
	
	me= this_player();
	
	level = F_LEVEL->get_level(me->query("combat_exp"));
	
	if (!me->query_temp("marks/jssju3_pay"))
		return notify_fail("什么？\n");
	
	if (arg == "no") {
		me->delete_temp("marks/jssju3_pay");
		return notify_fail("你决定不执行 refund 了。\n");
		}
	
	if (arg !="yes" )
		return notify_fail("请回到answer yes 或者 answer no\n");
	
	me->delete_temp("marks/jssju3_pay");
			
	if (me->query("deposit")< level*10000)
		return notify_fail("refund 需要黄金"+ level +"两，你的钱庄存款不够这个数目。\n");

	me->add("deposit",-level*10000);
	tell_object(me,HIR"付款完毕，钱庄转走"+ level + "两黄金，你可以使用 refund 命令了。
"NOR YEL"注意事项：只要不离开这个房间，你可以多次执行 refund 命令，改变多个技能，
但一旦你离开此地，则本次交易结束，下一次 refund 需要重新交款。\n"NOR);	
	me->set_temp("marks/refund_enable",1);
	return 1;
}

int do_refund(string arg){
	
	object me;
	int pot, level, mark, i;
	string *limit;
	
	me = this_player();
	
	if (!me->query_temp("marks/refund_enable"))
		return notify_fail("请先是用pay命令交付手续费。\n");
		
	if (me->query_temp("timer/refund")+2 > time())
		return notify_fail("执行该命令请间隔两秒。\n");
				
	if (!arg)	return notify_fail("你要返回你学过的那一项技能？\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("该项技能不存在或者你没有学过该项技能。\n");
	
	if (!SKILL_D(arg)->refundable()) 
		return notify_fail(HIW"系统规定，此项技能无法回复成潜能。\n"NOR);

	mark = 0;
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("该技能涉及到人物属性变化，无法回复成潜能。\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			if (level >=1) mark = 1;
			tell_object(me,"该技能为"+SKILL_D(limit[i])->name()+"（"+limit[i]+"）的基础：你拥有"+level+"级。\n");
		}
		if (mark)
			return notify_fail(HIW"唯有将所有关联武功先行洗去后才能洗去此技能。\n"NOR);
	}

	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"你曾经掌握了"+level+"级"+ SKILL_D(arg)->name()+"（"+arg+"），现已清零。\n"NOR);	
	tell_object(me,HIR"你在该技能上共花费了"+pot+"点潜能，现在全部返回。\n"NOR);
	tell_object(me,"你可以继续 refund 其他技能，如果你以任何方式离开此地，则该次过程结束。\n");
	
	me->add("learned_points", -pot);
	
	me->delete("annie/skill_cost/"+arg);
	me->delete_skill(arg);
	me->reset_action();
	
	log_file("REFUND_LOG", 
					sprintf("(%s)%s refund %d级%s，潜能恢复%d。\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					level,
					arg,
					pot,
				));
	me->save();			
	me->set_temp("timer/refund",time());				
	return 1;	
	
}


int valid_leave(object me, string dir)
{
	me->delete_temp("marks/jssju3_pay");
	me->delete_temp("marks/refund_enable");
	return ::valid_leave(me, dir);
}


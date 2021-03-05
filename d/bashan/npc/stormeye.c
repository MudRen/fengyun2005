// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("灰衣人", ({ "figure" }) );

        set("gender", "男性" );
		set("age",47);

        set("long","这人神情威猛，骨髓极大，但却很瘦，头发花白，一张瘦棱棱的脸上长\n着对三角眼，眼中凶光四射，他一直站得远远地，注视着神秘客。\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform tianwaifeixian") :),
             }) );

            set("inquiry",([
 		"九月初九"  : (: jice :),
 		"顾道人"  :"action灰衣人盯着$n，一字一字道：我听说有人想来暗算顾道人，莫非那人就是你？\n",
 		"顾剪秋"  :"action灰衣人盯着$n，一字一字道：我听说有人想来暗算顾道人，莫非那人就是你？\n",
           ]) );

        set_skill("sword", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("feixiansword", 200);
        set_skill("13-sword", 220);

        map_skill("sword", "feixiansword");
        map_skill("parry", "feixiansword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(MAG"噬魂剑"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("半旧的六品官袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void init()
{
	add_action("do_assassinate","assassinate");
	::init();
}

int jice()
{
	object me;
	me = this_player();
	if (me->is_fighting())
	{
		message_vision("$N道：九月初九，九月初九……恩，这个日子很可疑。\n",this_object(),me);
		return 1;
	}
	if(REWARD_D->riddle_check(me,"探流追源") != 2)
	{
		message_vision("$N道：九月初九，九月初九……恩，这个日子很可疑。\n",this_object(),me);
		return 1;
	}

	if (query("doing"))
	{
		message_vision("$N道：九月初九，九月初九……恩，这个日子很可疑。\n",this_object(),me);
		return 1;
	}

	message_vision("$N盯着$n，一字一字道：我听说有人想来暗算顾道人，莫非那人就是你？\n",this_object(),me);

	set("doing",1);

	call_out("do_abc",4,me);

	me->start_busy(40);

	return 1;
}

void do_abc(object me)
{
	object gu,jiang,feng,lu;
	object env = environment();
	feng=this_object();
	jiang = present("figure jiang",env);
	gu = present("gu jianqiu",env);
	lu = present("luo jiafei",env);

	if (!feng || !jiang || !gu || !lu || !me)
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}
	if (feng->is_fighting() || jiang->is_fighting() || gu->is_fighting() || lu->is_fighting() || me->is_fighting())
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}
	if (environment(me) != env)
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}

	message_vision(CYN"$N盈盈一笑，对$n道：剪秋，时辰将至，且等我去后院将金盆捧来。\n",lu,gu);
	message_vision("$N起身向众人一礼，转入后院。\n\n"NOR,lu);
	destruct(lu);

	feng->set("no_kill",1);
	jiang->set("no_kill",1);
	gu->set("no_kill",1);

	me->stop_busy();

	me->set_temp("annie/assassin",1);

	tell_object(me,HIR"强敌已去，此刻正是刺杀(assassinate)顾道人的大好时机！\n"NOR);

	call_out("timeout",20,feng,jiang,gu,me);
}

void timeout(object feng,object jiang,object gu,object me)
{
	remove_action("do_assassinate","assassinate");

	me->set_temp("annie/assassin",0);
	message_vision(CYN"\n$N皱了皱眉头，对众人道：葭飞怎的还没回来？——请恕剪秋失礼。\n",gu);
	message_vision("$N站起身子，也向后院行去。\n"NOR,gu);
	feng->set("no_kill",0);
	jiang->set("no_kill",0);
	set("doing",0);
	destruct(gu);
	return;
}

int do_assassinate(string arg)
{
	object me = this_player();
	object gu,jiang,feng,target;
	object env = environment();
	feng=this_object();
	jiang = present("figure jiang",env);
	gu = present("gu jianqiu",env);


	if (REWARD_D->riddle_check(me,"探流追源") != 2)
		return notify_fail("你要干什么？\n");
	if (!me->query_temp("annie/assassin"))
		return notify_fail("你要干什么？\n");
	if (!arg)
		return notify_fail("你要刺杀谁？\n");
	if (!target=present(arg,env))
		return notify_fail("你要刺杀谁？\n");
	if (target != gu)
		return notify_fail("小心看仔细了，不要杀错了人，打草惊蛇！\n");
	

	me->set_temp("annie/assassin",0);

	message_vision(HIR"\n$N眼中厉芒骤绽，右手按在腰间，盯住$n，\n"NOR,me,gu);
	message_vision("$N猛地回头，锋锐的目光扫过，身形乍展，拦阻在$n面前！\n"NOR,feng,me);

	feng->kill_ob(me);
	me->kill_ob(feng);

	remove_call_out("timeout");
	call_out("timeout",20,feng,jiang,gu,me);
	call_out("nexts",16,feng,jiang,gu,me);
	return 1;
}

void nexts(object feng,object jiang,object gu,object me)
{
	string msg;
	if (!feng || !jiang || !gu || !me)
	{
		set("doing",0);
		return ;
	}
	if (environment(me) != environment(feng))
	{
		set("doing",0);
		return ;
	}
	if (!is_fighting())
	{
		ccommand("heng");
		set("doing",0);
		return ;
	}
	remove_call_out("timeout");

	message_vision(CYN"\n$N与$n酣战之刻，神秘客陡然压低了自己的斗笠，绕过你们的战局，欺近顾道人身前！\n\n"NOR,me,feng);

	msg=HIR BLK"神秘客眼神忽然锐利起来，手中长刀在一瞬间已然出鞘，甚至连阳光也跟不上刀的轨迹，\n只能见到一道灰色的阴影随着刀锋射出。紧接着在长刀斩过的空间里，空气仿佛突然被撕\n碎，被挤压，暴发出尖锐的啸叫，一股匹练似的疾风随着神秘客晃身踏步前斩的动作，以\n无可阻挡之势穿越而过！\n\n"HIB"－－－－－－－－－－－－－　　煮　鹤　焚　琴　！\n\n"NOR"结果只听见顾剪秋一声惊叫，"HIB"寸尺刀"NOR"已在他心口划出一道深及见骨的可怕伤口！！\n( 顾剪秋"RED"已经陷入半昏迷状态，神智全失，如风中残烛，随时都可能断气。"NOR" )\n\n";
	message_vision(msg,feng,me);
	gu->receive_wound("kee",1,jiang);
	gu->die();

	message_vision(CYN"$N一击得手之后再不恋战，提气掠起三丈，足尖在亭柱上一点，电射而去。\n"NOR,jiang);
	message_vision(CYN"\n$N一声狂吼，挥舞手中长剑向$n急攻数式，趁隙凌空拔起，向神秘客消失的方向追去！\n\n"NOR,feng,me);

	REWARD_D->riddle_set(me,"探流追源",3);

	tell_object(me,WHT"你稳住脚步，看看脚下的尸体，不知如何是好。\n不过顾剪秋既是已死，此事也应已了结。\n"NOR);

	destruct(jiang);
	destruct(this_object());
	return;
	
}


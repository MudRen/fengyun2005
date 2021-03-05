// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("小无", ({ "xiao wu","wu","xiaowu" }) );
        set("title",RED"枫叶境"NOR);
		set("nickname",WHT"从此不再等你"NOR);
        set("gender", "女性" );

//		set("group","couple");

		set("age",16);

set("long","小无原名萧无，因与百年前一位先人同名，遂自号为小无。只是她
的朋友们更喜欢叫她萧没有——并非因为无就是没有，而是因为她
欢乐的时候，你就会没有烦恼，她悲伤的时候，你就会没有微笑，
而若有人敢惹她生气，这个人一定会从此“没有”。
\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"小无望着远山，悠悠道：这么大人了，就算仍是小孩，难道还不知道世上是没后悔药好吃的么？\n",
		"小无微笑道：我不是说了么？罗得的妻子一回头就成了盐柱，所以，我们便不要再回头。\n",
		"小无摇了摇头道：后悔这件事，结果从来是只能独自继续懊悔的。\n",
	}) );

        set("reward_npc", 1);
        set("difficulty",11);	// Big big npc.

		set("no_arrest",1);

        set("combat_exp", 10000000);
		set("class","moon");

		set_skill("force",320);
		set_skill("divineforce",200);
		map_skill("force","divineforce");


		set_skill("dodge",320);
		set_skill("stormdance",200);
		map_skill("dodge","stormdance");

		set_skill("sword",320);
		set_skill("qiuzhi-sword",200);
		map_skill("sword","qiuzhi-sword");

		set_skill("parry",320);
		map_skill("parry","qiuzhi-sword");


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

		setup();

        carry_object(__DIR__"obj/xiaosword")->wield();
        carry_object(__DIR__"obj/xiaocloth")->wear();

}


void smart_fight()
{
	object me,target;
	me = this_object();
	target = select_opponent();

	if (ccommand("perform force.check_gspm"))
	{
		ccommand("perform force.guishenpomie");
		stop_busy();
		return;
	}
	ccommand("perform hanmeiluo");
}


void die()
{
	object me = this_object();
	object he;
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");

	message_vision(CYN"\n小无衣角扬风，后避到争雄崖边"NOR,me);

	he = present("xiao fang",environment());
	if (he)
		message_vision(CYN"，深深地看了$N一眼，嘴角还挂着一丝浅浅的微笑。\n\n"NOR,he);
	else
		message_vision(CYN"。\n\n"NOR,me);
	message_vision(HIB"小无轻轻地呼出一口气，转身自悬崖边跃下，紫色的衣裙在风中绽成一只飞舞的蝴蝶。\n\n"NOR,me);
	if (he)
		he->icic(me);
	
	move(room);
	::die();

}

int icic(object he)
{
	object room;
	room = find_object("/obj/void");
	if (!room)
		room=load_object("/obj/void");


	message_vision(CYN"小无的眼色一黯，转瞬间又展露出灿烂的笑容，伸出手与$N紧紧相握。\n\n"NOR,he);
	message_vision(CYN"小无眼波流转，轻笑道：这辈子我不会原谅你。然而我可以给你一个机会……\n\n"NOR,he);
	message_vision(CYN"$N现出欣慰的神色，接道：让我们下辈子还在一起。\n\n"NOR,he);
	message_vision(HIY"$N同小无相视而笑，双双自悬崖边跃下，一阵微风卷过，从此不见踪迹。\n\n"NOR,he);

	move(room);
	::die();
}

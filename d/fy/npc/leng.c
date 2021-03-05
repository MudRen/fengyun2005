// garrison.c

#include <ansi.h>

inherit NPC;
#define LOWER_LIMIT 800000
#define DUMP_PLACE  AREA_LAOWU"road0.c"
void create()
{
        set_name("冷若霜", ({ "leng ruoshuang", "leng" }) );
        set("long",
"这位美人人如其名，给人一种高不可攀，冷若冰霜的感觉．
但她是太有媚力，太令人着迷，你真想和她认识认识（ｋｎｏｗ）\n");
        set("attitude", "heroism");
		set("title", HIW "冰山"NOR);
		set("gender", "女性");
		set("per", 30);
		set("age",19);
        set("combat_exp", 100000);

		set("inquiry", ([
			"罗刹牌": "罗刹牌是西方玉罗刹的镇山之宝，却被他儿子输给了赌场的蓝胡子，
没想到却又被蓝胡子的老婆偷走，这事儿玉罗刹知道了肯定不会甘休，
所以我们只能拉个垫背的了。\n",
			"罗刹": "罗刹牌是西方玉罗刹的镇山之宝，却被他儿子输给了赌场的蓝胡子，
没想到却又被蓝胡子的老婆偷走，这事儿玉罗刹知道了肯定不会甘休，
所以我们只能拉个垫背的了。\n",
			"罗刹牌": "罗刹牌是西方玉罗刹的镇山之宝，却被他儿子输给了赌场的蓝胡子，
没想到却又被蓝胡子的老婆偷走，这事儿玉罗刹知道了肯定不会甘休，
所以我们只能拉个垫背的了。\n",
			"蓝胡子":	"蓝胡子是这儿的老板，就在后面的厢房里。\n",
			"玉罗刹":	"玉罗刹是西方神教的头面人物，没有人知道他的真面目。\n",		
			"替死鬼":	YEL"罗刹牌"CYN"的事儿，总得有个人"YEL"顶缸"CYN"才行，不过，如果你实在有"YEL"苦衷"CYN"，
五两金子，我就不难为你了。\n",
			"苦衷":	"五两金子，我就不难为你了。\n",	
			"顶缸":		(: command("point") :),		
			"垫背":		(: command("point") :),		
			"老婆":		"就是那个李霞呀！\n",
			"李霞":		"跑了，找不到了！\n",
		]));
				
		
		
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/move", 100);

        setup();
        carry_object(__DIR__"obj/goldcloth")->wear();
}

void init()
{
	::init();
	add_action("do_know","know");
}

int do_know()
{
	object me;
	object dump;
	me = this_player();
	if((int) me->query("combat_exp") >= LOWER_LIMIT)
	{
		tell_object(me,"冷若霜叹了口气，＂看来今天只好拉你作"YEL"替死鬼"NOR"了．＂\n");
		tell_object(me,"冷若霜趁你不备，悄悄拂了一下你的睡穴．\n");
		me->unconcious();
		if (REWARD_D->riddle_check(me,"计取罗刹")<1)
			REWARD_D->riddle_set( me, "计取罗刹",1);
		dump = find_object(DUMP_PLACE);
		if (!dump) dump = load_object(DUMP_PLACE);
		me->move(dump);
	}	
	else
	{
		message_vision("$N向$n挤出一丝勉强的笑容，道：＂好人！你帮不到我．＂\n",this_object(),me);
	}
	return 1;
}

int accept_object(object who, object ob){
	
	if (!REWARD_D->riddle_check(who,"计取罗刹"))	return 0;
	
	if (!ob->query("money_id"))	return 0;
	
	if (ob->query("value")<50000)	{
		command("say 这么穷，那你只能自认倒霉了。");
		return 0;
	}
	
	command("sigh");
	command("say 好吧，你我就算两清了。");
	REWARD_D->riddle_clear(who,"计取罗刹");
	return 1;
}
#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("昭红", ({ "girl" }) );
	set("title", HIM "风云名妓"NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
昭红是风云城的名妓，如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 3000);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
		if((int)obj->value() >= 1000) me->add_temp("marks/chick1",1);
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
	if((int)me->query_temp("marks/chick1") <=0)
	{
        command("say 哎哟．．．这位" + RANK_D->query_respect(me) +
	"，您还没给赏就想占人家的便宜么？");
	return 1;
	}
	me->add_temp("marks/chick1",-1);
	message_vision("$N轻飘飘地向$n走过来，温柔的抚弄$n的黑发．．．\n",this_object(),me);
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
        if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		if(!DROP_CMD->do_drop(me, inv[i])) {
			destruct(inv[i]);
		}
	}
	me->unconcious();
	me->full_me();
	wo = new(__DIR__"obj/wo");
	wo->move(me);
	return 1;
}

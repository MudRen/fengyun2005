#include <ansi.h>
inherit NPC;

void create()
{
        set_name("叶雪", ({ "ye xue", "ye", "xue" }) );
        set("gender", "女性");
        set("per", 30);
        set("age", 23);
        set("class", "ghost");
        create_family("幽灵山庄", 3, "弟子");
        set("combat_exp", 250000);
        set("long",	"她的人就象豹子一样，美丽、敏捷、冷静、残酷。\n");
        set("no_arrest",1);
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("taiji", 80);
        set_skill("parry",100);
        set_skill("five-steps", 80);
		map_skill("dodge", "five-steps");
		map_skill("move", "five-steps");
		map_skill("unarmed", "taiji");
        setup();
		carry_object(__DIR__"obj/cloth2")->wear();
}



int accept_object(object who, object ob)
{
		object		book;
        if((string)ob->name() != "白剑") return 0;
		command("say 多谢这位" + RANK_D->query_respect(who) +"把我表哥的白剑带给我。这本书请收下。");
		book = new(BOOKS"foreknowledge_30");
		if (!book->move(who))
			book->move(environment(who));
        return 1;
}


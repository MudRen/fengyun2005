
inherit NPC;

void create()
{
	set_name("彩儿", ({ "cai er" }) );
	set("gender", "女性" );
	set("age", 16);
	set("long",
"一个眉清目秀的小姑娘正在忙碌地修补着渔网。
据说她出生的那一天，她父亲正好抓到一条美丽的五彩小鱼，所以就叫她彩儿。\n");

	set("combat_exp", 100);
	set("attitude", "friendly");
	set("per",17);
	set("chat_chance", 3);
	set("title", "渔家女");
	set("chat_msg", ({
        "彩儿自言自语道：“希望今年能够抓到五彩小鱼。”\n",
        "彩儿低头沉思。\n",
    	"彩儿飞快地织补着渔网。\n",
    }));	
	set("inquiry", ([
		"rainbow fish" : "五彩小鱼可难钓到了，而且一出水就开始腐烂。\n",
		"五彩小鱼" : "五彩小鱼可难钓到了，而且一出水就开始腐烂。\n",
	]) );
	setup();

    carry_object("/obj/armor/cloth")->wear();
    add_money("coin", 30);
}

int accept_fight(object me)
{
        command("say 我哪里是您的对手？");
        return 0;
}


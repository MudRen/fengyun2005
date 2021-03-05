// beggar.c

inherit NPC;
#include <ansi.h>
int answer_snake();
void create()
{
        set_name("耍蛇乞丐", ({ "playsnake beggar" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", 
"这是一个靠在四处流氓卖艺，耍蛇乞讨为生的中年乞丐，对于天下毒蛇的门道 
可说是十分精通。 \n");
        set("combat_exp", 10000);
        set("str", 30);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 5);
        set("chat_chance", 2);
		
        set("chat_msg", ({
        "耍蛇乞丐双臂缠绕着各式蛇蟒，嘿嘿冷笑着看着过往行人。\n",
        "耍蛇乞丐大声吆喝着：看一看，瞧一瞧哎，毒蛇虽毒，这蛇胆可
是宝货，专治绝症呦。\n",   
        }) );
		set("inquiry",([
			"毒蛇" : (:answer_snake:),
			"蛇" : (:answer_snake:),
			"snake" : (:answer_snake:),
			]) );
        setup();
    carry_object("obj/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
		object snake;
		if (obj->query("money_id") == "gold" && obj->query_amount() >=10)
		{
			message_vision(
YEL"$N颔首道：好，既然"+RANK_D->query_respect(me)+"如此慷慨，我也不藏私了，天下有
三大毒蛇，一为响尾蛇，一为竹叶蛇，还有一种王蛇却是特别难寻，不过大爷运气好，我 
这里有一条，就赠与大爷算是回报吧！ \n"NOR,this_object());
			message_vision("\n$N从背中布袋里放出条金色小蛇，嘿嘿冷笑了一声。\n",this_object());
			snake = new(__DIR__"wangsnake");
			snake->move(environment(this_object()));
			snake->kill_ob(me);
		}else
		{
			command("smile");
			command("say 多谢这位" + RANK_D->query_respect(me) + 
	"，您好心一定会有好报的！");
		}
        return 1;
}

int answer_snake()
{
	object me;
	me = this_player();
	message_vision(
YEL"$N三角斜眼看了看$n，冷冷道：世人都道毒蛇毒，您怎么反倒询问 
起毒蛇来了？奇怪奇怪。嘿嘿，若是您诚心打听的话，总得意思意思吧！ \n"NOR,this_object(),me);
	return 1;
}
 

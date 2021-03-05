#include <ansi.h>
inherit NPC;

void create()
{
        set_name("姬冰雁", ({ "bingyan" }) );
        set("gender", "男性" );
        set("age", 42);
	set("long","
他虽在开怀大笑，但一双眼睛仍锐利得如同鸷鹰。懒惰、迟钝、犹豫不
决，虽是大多数人通常有的毛病，但无论什么时候，无论是谁，也休想
在他这张棱角突出的脸上，找出丝毫这种神情来，他整个人就好像是精
明和强锐的化身。他就是楚留香的死党，很有风度的姬冰雁。\n");
	set("combat_exp", 1000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "
姬冰雁苦笑着道：“我在[33m沙漠[32m里整整流浪了五年，我那五年是如何过的，
只怕谁也想象不到，有一次，我竟活生生被埋在沙堆下，直到两天后，
才被路过的骆驼队救出去，那该死的沙漠虽然给了我一辈子都花不光的
财富，却也给了我满身风湿。\n",
        }) );

	set("inquiry",([
		"沙漠":"活在沙漠里的人，早已被锻炼成铁一般的坚强，坚强得
你连想都想不到，而你的心，你的骨头，却早已被酒肉，被女人，被
太舒服的生活所软化了，"YEL"沙漠里的生活"CYN"，已不是你们所能适应。\n",
		"desert":"活在沙漠里的人，早已被锻炼成铁一般的坚强，坚强得
你连想都想不到，而你的心，你的骨头，却早已被酒肉，被女人，被
太舒服的生活所软化了，"YEL"沙漠里的生活"CYN"，已不是你们所能适应。\n",
		"沙漠里的生活":"沙漠里的人，为了生存所做出的事，你们非但做不出，
而且想都不敢去想的。他们为了怕身体里的水消耗，能整天不说话，
也不动，他们肚子饿时，能将蜥蜴当做火腿来吃，他们渴时，会趴在
地上闻出沙下面一丈深地方的湿气，为的只是去吸吮地下沙子里的水！\n",
	]));
		
	set("attitude", "friendly");
	set("class","baiyun");
	
    	set_skill("unarmed", 150);
    	set_skill("force", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("calligraphy", 120);
    	set_skill("chessism", 150);
    	set_skill("feixian-steps", 120);
	set_skill("move",120);
    	map_skill("unarmed", "calligraphy");
    	map_skill("force", "chessism");
    	map_skill("dodge", "feixian-steps");
    	map_skill("move","feixian-steps");

        setup();
        carry_object(__DIR__"obj/jcloth")->wear();

}

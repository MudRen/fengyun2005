inherit NPC;
#include <ansi.h>
void create()
{
        set_name("白玉京", ({ "bai yujing", "bai", "yujing" }) );
        set("nickname", HIC"天上"NOR);
        set("title", "长生剑客");
        set("gender", "男性" );
        set("age", 24);
 	set("per", 20);
	set("attitude","peaceful");
        set_temp("apply/damage",150);
        set_temp("apply/attack",200);

        set("long",
		"天上白玉京，旧靴子，旧剑鞘，但穿着一身崭新的衣服。\n"
	);

        set("combat_exp", 4000000);
        set("score", 200000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"白玉京喟然长叹一声，默然不语。\n"	
        }) );
        set("inquiry",([
	        "袁紫霞"  :"袁姑娘竟会是青龙会的红旗老幺？她为什么骗我？\n",
	        "yuan"  :"袁姑娘竟会是青龙会的红旗老幺？她为什么骗我？\n",
	        "长生剑"  :"哎。。仙人抚我顶，结发受长生。昔日的长生剑早已不知流落何方？如果能。。\n",
	        "sword"  :"哎。。仙人抚我顶，结发受长生。昔日的长生剑早已不知流落何方？如果能。。\n",
                ]) );

        set_skill("move", 100);
        set_skill("parry", 200);
        set_skill("dodge", 180);
        set_skill("force", 100);
	set_skill("unarmed", 180);
	set_skill("bai-quan",280);
        set_skill("sword",200);
	set_skill("qingpingsword",150);
        set_skill("qingpingforce",120);
        set_skill("chaos-steps",150);
        
	map_skill("force", "qingpingforce");
	map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
     	map_skill("unarmed","bai-quan"); 
        setup();
        carry_object("/d/chenxiang/npc/obj/newcloth")->wear();
        carry_object("/d/chenxiang/npc/obj/oldboots")->wear();
}

void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) 
        {
                call_out("greeting", 1, me);
        }
}


int greeting(object me)
{
	if (me && environment(me) == environment(this_object()))
    	message_vision("\n$N凝视着窗外。。许久。。许久。。。
$N对$n缓缓道：为何要骗我？袁姑娘究竟是爱我还是恨我？\n", this_object(), me);
        return 1;
}

int accept_object(object me, object obj)
{
	object bai, ob, sword;
	bai = this_object();
	
	if (F_LEVEL->get_level(me->query("combat_exp"))<30) {
		message_vision(CYN"$N看了看你，无奈地摇了摇头。\n"NOR, bai);
		tell_object(me,"（解此谜题至少需要等级30）\n");
		return 0;
	}
	
	
	if( (string) obj->query("name") == "孔雀图" && obj->query("real"))
	{
		environment(me)->answer_notify(bai,0);
        message_vision(HIY "\n$N对$n缓缓道：为了一张孔雀图，尔虞我诈！人间可还有真情在？\n你可否告知我袁姑娘究竟是爱我还是恨我？（answer love/hate）\n"NOR, this_object(), me);
		return 1;
	}
	else if( (string) obj->query("name") == HIG "长生剑"NOR )
	{
        message_vision(HIW "\n$N颤抖着双手，挣扎着想接过宝剑，但‘噗通’一声，摔倒在地，宝剑也落到地上。\n这绝代剑客，竟连自己的宝剑都拿不稳了。\n"NOR, this_object());
		ob = present("floor", environment(this_object()));
		sword = new("/d/tieflag/obj/csword");
		sword->move(ob);
		return 1;
	}
	else
	{
	       	tell_object(me,"白玉京说道：这不是我想要的。\n");
        	return 0;
        }
}

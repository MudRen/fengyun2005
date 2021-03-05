#include <ansi.h>
inherit F_VENDOR;
inherit NPC;
void create()
{
        set_name("老板娘", ({ "pretty woman","woman" }) );
        set("gender", "女性" );
        set("title", "风韵尤存");
        set("nickname",HIR"最漂亮的"NOR);
        set("age", 37);
        set("long", 
"说她是最漂亮的老板娘毫不夸张，她的确是个非常美的女人，弯弯
的眉，大大的眼睛，嘴唇玲珑而丰满，看来就像是个熟透了的水蜜
桃，无论谁看见都忍不住想咬一口。\n");
        set("combat_exp", 350000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "老板娘吃吃地一笑：没有见过陆小凤的人，是怎么也不会想到他的两条眉毛
竟然是长在嘴上的。\n",
        "老板娘恨恨道：我前些日子和那四条眉毛在房里喝了许多酒，但那个死鬼竟然
还是什么事没有，什么醋都不吃，气死我了。\n",
        "老板娘扑哧一笑道：这两个大混蛋做的事，我非但一点也不懂，简直是越
想越糊涂。\n",
	}) );
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("zhaixin-claw",50);
        set_skill("anxiang-steps",50);
        set_skill("parry",50);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","anxiang-steps");
        
			set("vendor_goods", ([
			"/obj/generate/commonweapon/30/axe":20,
			"/obj/generate/commonweapon/30/blade":20,
			"/obj/generate/commonweapon/30/fist":20,
			"/obj/generate/commonweapon/30/hammer":20,
			"/obj/generate/commonweapon/30/spear":20,
			"/obj/generate/commonweapon/30/staff":20,
			"/obj/generate/commonweapon/30/sword":20,
			"/obj/generate/commonweapon/30/throwing":20,
			"/obj/generate/commonweapon/30/whip":20,
			]) );
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}
int accept_fight(object me)
{
        command("say 小女子若有怠慢，您可千万别介意，小女子给您作揖陪个不是。\n");
        return 0;
}

void init()
{
    ::init();
    add_action("do_vendor_list", "list");
}

void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/30/axe":20,
	"/obj/generate/commonweapon/30/blade":20,
	"/obj/generate/commonweapon/30/fist":20,
	"/obj/generate/commonweapon/30/hammer":20,
	"/obj/generate/commonweapon/30/spear":20,
	"/obj/generate/commonweapon/30/staff":20,
	"/obj/generate/commonweapon/30/sword":20,
	"/obj/generate/commonweapon/30/throwing":20,
	"/obj/generate/commonweapon/30/whip":20,
	]) );
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


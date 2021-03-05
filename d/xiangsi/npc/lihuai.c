inherit NPC;
#include <ansi.h>
void create()
{
	object weapon;
        set_name("李坏", ({ "li huai","li" }) );
        set("gender", "男性" );
		set("nickname",HIG"又见飞刀"NOR);
		set("age",20);
		set("c",HIG"看来身上并无丝毫伤痕。"NOR);
        set("reward_npc", 1);
		set("difficulty", 10);
		set("attitude","friendly");
        set("max_force", 15000);
		set("NO_KILL",1);
        set("force", 15000);
        set("force_factor", 1);
        set("long","一个风尘仆仆的少年人，穿一身灰扑扑的衣裳，\n看起来本应该无比落魄，可是却又无比精神。\n");
        create_family("风云一刀", 4, "人杰");
        set("combat_exp", 10000000);

        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
		set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
        setup();
        weapon = carry_object("/obj/armor/cloth");
		weapon->set("name",HIR BLK"灰扑扑的衣裳"NOR);
		weapon->wear();
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	write("一个风尘仆仆的少年人，穿一身灰扑扑的衣裳，\n看起来本应该无比落魄，可是却又无比精神。\n他看起来约二十多岁。\n他风度翩翩，如玉树临风。\n他"CYN"让人觉得气质文弱"GRN"，武功看起来好象"HIB"初窥门径"NOR"，出手似乎极轻。\n他"+query("c")+"\n他右手捏着一块"YEL"豆腐"NOR"(Tofu)\n  身穿"HIR BLK"灰扑扑的衣裳"NOR"(Cloth)\n");
	return 1;
}

void init()
{
	add_action("do_look","look");
	::init();
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

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	object weapon;
	set_name("不三", ({ "the king of boasters", "busan" }) );
	set("class","blowman");
	set("gender", "无性" );
	set("age", 25);

	set("nickname",HIY"天下第一肺，举世无双嘴"NOR);
	set("title",HIC"神牛国王"NOR);

	set("attitude", "friendly");

	set("long","据说不三每几个月就要蜕一次皮，从它脸上蜕\n下来的部分就是坚韧无比的神牛皮。\n");

	set("chat_chance", 100);
	set("chat_msg", ({
	CYN"不三摇头晃脑道：你知不知道，当今第一高手，就是在我的指导下诞生的。\n"NOR,
	CYN"不三从鼻子里哼了一声：我一天就能赚个二十万潜能，你和我比？\n"NOR,
	CYN"不三对你说：我现在不杀钱了，当年我杀钱的时候，一天八千两黄金也是有的。\n"NOR,
	CYN"不三拖长声音道：什么？你不认识我？我可是名动天下的一代高手，这些年死在我手下的人，没有十万也有二十万了。\n"NOR,
	CYN"不三叹道：吹牛也是一种本事，天底下又有几个人能面不改色心不跳的大吹牛皮呢？\n"NOR,
	CYN"不三轻轻一张嘴，你只觉狂风卷过，无数口水飞沫雨似的洒了出去，很快就把百里外的大明湖注得满满当当。\n"NOR,
	CYN"不三低头吹了吹自己身上的大牛皮，大牛皮顿时胀得鼓鼓囊囊。\n"NOR,
	CYN"不三自言自语道：我可是天上少有，风云唯一的奇才，为什么没有人欣赏我呢？\n"NOR,
	}) );

	set("combat_exp", 1);

	setup();

	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",YEL"大牛皮"NOR);
	weapon->set("long","你摊开牛皮一看，原来里边空空，什么也没有。");
	weapon->wear();

}





int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	write("据说不三每几个月就要蜕一次皮，从它脸上蜕下来的部分就是江湖传说里坚韧无比的神牛皮。\n他看起来约二十多岁。\n他看来呆头呆脑的。\n他看起来圆圆滚滚，吹功看起来好象"HIR"深不可测"NOR"，出手难知深浅。\n他"HIG"看来身上并无丝毫伤痕"NOR"。\n他身穿"NOR YEL"大牛皮"NOR"(Cloth)\n");
	return 1;
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("不三目前共学过一种技能：\n\n自吹自捧之术 (blowing)                   - "HIW"深不可测"NOR" 400/    0\n\n");
	return 1;
}

void init()
{
	object ob;
	::init();
	add_action("do_listskill","skills");
	add_action("do_look","look");
}


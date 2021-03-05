inherit NPC;
#include <ansi.h>

void create()
{
	set_name("野熊", ({ "bear"}) );
	set("race", "野兽");
	set("gender", "雄性");
	set_temp("condition_type",YEL"<冬眠中>"NOR);
	set("age", 6);
	set("long", "
这是一只皮糙肉厚的野熊，生性凶恶，力大无比。不过，它现在正在
呼呼地睡大觉。\n");
	
	set("chat_chance",1);
    	set("chat_msg",({
		CYN"\n野熊翻了个身，继续呼呼地睡大觉。\n\n"NOR,
    	}) );  
	
	set("combat_exp", 200000);
		
	set_temp("apply/attack", 50);
	set_temp("apply/dodge",50);
	set_temp("apply/move",40);
	set_temp("apply/armor", 100);
	setup();
	carry_object(__DIR__"obj/palm_w");
}

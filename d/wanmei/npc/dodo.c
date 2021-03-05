inherit NPC;
void create()
{
    	set_name("金丝雀", ({ "sparrow" }) );
        set("race", "飞禽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只闪亮的金丝雀 \n");
    	set("combat_exp", 3000);
        set("attitude","peaceful");

        set_temp("apply/dodge", 100);
	set("chat_chance", 7);
        set("chat_msg", ({
        	"小金丝雀叽叽的叫！ \n",
        	"金丝雀用嘴整理羽毛。 \n"
        }) );
        setup();
}

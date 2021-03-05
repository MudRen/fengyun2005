inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖面的老头子", ({ "lao zhang", "zhang" }) );
        set("gender", "男性" );
        set("age", 57);
        set("long",
                "他的确已很老了，须发都已斑白，此刻正坐在那里，低着头喝面汤，
挂在摊头的纸灯笼已被油烟熏得又黑又黄，就像是他的脸。\n");
		set("per", 5);
		set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
        	"obj/food_item/soup" : 120,
            	"obj/food_item/soup1" : 120,
            	"obj/food_item/soup2" : 120,
            	"obj/food_item/soup3" : 120,
            	"obj/food_item/soup4" : 120,
            	"obj/food_item/soup5" : 120,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

void reset()
{
        set("vendor_goods", ([
        	"obj/food_item/soup" : 120,
            	"obj/food_item/soup1" : 120,
            	"obj/food_item/soup2" : 120,
            	"obj/food_item/soup3" : 120,
            	"obj/food_item/soup4" : 120,
            	"obj/food_item/soup5" : 120,
        ]) );	
}
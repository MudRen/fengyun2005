// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("田膨郎", ({ "tianpeng lang","tianpeng" }) );
	set("gender", "男性" );
	set("long","此人双眼大如铜铃，但双眼相距奇远，一看到此人，你就发现他的名字和他本人真象！\n");
	set("age", 45);
	set("combat_exp", 50000);
	set("attitude", "friendly");
    set("inquiry", ([
           "蜡丸" : (: tell_him :),
           "lawan" : (: tell_him:),
    		"王石匠" : 	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"wang" :	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"大恩人":	"恩，在下一生不受人恩惠，所以才活到今天。\n",
        	"恩人":		"恩，在下一生不受人恩惠，所以才活到今天。\n",
    
    ]));
    
    
            
        		
        set("vendor_goods", ([
                __DIR__"obj/yu1":8,
                __DIR__"obj/yu2":8,
                __DIR__"obj/gu":10,
                __DIR__"obj/mi":8,
        ]) );


	setup();
	carry_object("/obj/armor/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_vendor_list", "list");

}
int tell_him()
{
    	object me,obj;
		int n;
    	me =this_player();

    	if (REWARD_D->riddle_check(me,"魂断鹊桥")!= 9)	return 0;
        		
    	if( !me->query_temp("marks/ami"))    
    	{
        	if(me->query_temp("marks/asked_yaofang") <  5)       {
           		tell_object(me,"田膨郎道：噢．．你想要蜡丸．．但你知道不知道这蜡丸会给你杀身之祸？\n");
           		tell_object(me,"田膨郎道：凡是从我这里拿了蜡丸的人一出门就被人刺杀死了，");
            	tell_object(me,HIR"无一幸免，无一幸免！\n"NOR);
            	me->add_temp("marks/asked_yaofang",1);
            	return 1;
        	}
        	else if(me->query_temp("apply/jade_pro"))        {
//            	me->set_temp("marks/ami",1);
            	obj = new(__DIR__"obj/lawan");
            	obj->set("real_lawan_id",me->query("id")); 
            	tell_object(me,CYN"田膨郎道：唉，既然你不怕死．．．\n\n"NOR);
            	tell_object(me,YEL"田膨郎转过身去，不知从那里摸出个蜡丸．．． \n\n"NOR);
            	tell_object(me,RED"就在田膨郎要把蜡丸给你的一瞬间，红光一闪，一股血从他的颈动脉喷出．．．
他的手突然僵硬．．．蜡丸掉在了地上。\n"NOR);
            	obj->move(environment(this_object()));
            	tell_object(me,WHT"\n你听到你脖子上＂叮＂的一声．．．还好！幸亏戴着玉脖套！！\n"NOR);
            	me->delete_temp("marks/asked_yaofang");
            	this_object()->die();
            	return 1;
        	}
        	else       {
            	tell_object(me,CYN"田膨郎道：唉，既然你不怕死．．． \n\n"NOR);
            	tell_object(me,YEL"田膨郎转过身去，不知从那里摸出个蜡丸．．． \n"NOR);
            	tell_object(me,RED"就在田膨郎要把蜡丸给你的一瞬间，你突然感到脖子上针扎般的痛．．．\n"NOR);
            	message_vision(HIR"红光一闪，一股血从$N的颈动脉喷出．．．\n"NOR,me);
            	me->set_temp("last_damage_from","在沉香镇被无名刺客刺杀。\n");
            	me->delete_temp("marks/asked_yaofang");
            	me->die();
            	return 1;
        	}
        	return 1; 
    }
    message_vision("$N说：“蜡丸？什么蜡丸？没听说过。“\n",this_object());
    return 1;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/yu1":8,
                __DIR__"obj/yu2":8,
                __DIR__"obj/gu":10,
                __DIR__"obj/mi":8,
        ]) );
}

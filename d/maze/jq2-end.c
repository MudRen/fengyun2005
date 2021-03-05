// Sinny-silencer@fy4 workgroup 


// well, should we let everyone come, or just the quester?

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "无间堂");
	set("long", @LONG
一间十分开阔的大堂，四角高燃着牛烛，却是一种绿色的火焰，大堂正中处只
有一个遍体鳞伤，披头散发，衣不蔽体的高大囚犯被四根粗如腕臂的铁链穿过四肢
骨筋，牢牢的吊在当中。地上散落着刀剑和拷问犯人的刑具，而前面，是一个高达
数丈的炉鼎，里面烈火四窜，堂中仿佛炼狱一般。。。。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq2-exit",
		
	]));
        set("objects", ([
                __DIR__"npc/jq2-guosongyang" : 1,
        ]) );
        set("item_desc", ([
		"铁链": "四条粗如腕臂的铁链穿过郭嵩阳的四肢，只有用尽真力方能拉断（pull）。\n",
		"shackle": "四条粗如腕臂的铁链穿过郭嵩阳的四肢，只有用尽真力方能拉断（pull）。\n",
		"chain": "四条粗如腕臂的铁链穿过郭嵩阳的四肢，只有用尽真力方能拉断（pull）。\n",
	]) );
	setup();
	
}


void	init(){
	add_action("do_pull","pull");
}

int do_pull(string arg){
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();
        
        if (me->is_busy())
        	return notify_fail("你现在正忙。\n");
        	
        if (!arg && arg!="铁链"&& arg!="shackle") {
                tell_object(me,"你想拉开什么？\n");
                return 1;
        }
        if (!ob=present("guo songyang",this_object())) {
                tell_object(me,"你想拉开什么。\n");
                return 1;
        }
        if (ob->query("loose")) {
                tell_object(me,"郭嵩阳身上的铁链已经被解开了。\n");
                return 1;
        }
        if (me->query("force_factor")>= 70) {
        	message_vision(HIC"$N双手握紧铁链，丹田气息流转，猛地大叫一声，“开！”，铁链应声而断！\n"NOR,me);
        	ob->set("loose",1);
        	ob->delete_temp("condition_type");
        	me->start_busy(4);
        	call_out("kill_him",6,me,ob);
        }
        	else {
        	message_vision(CYN"$N试着拉了拉铁链，毫无动静（需enforce 70）\n"NOR,me);
        }
              
        return 1;
}


int kill_him(object me, object ob){
	if (!me || !ob || environment(me)!= environment(ob) )
		return 1;
	ob->delete("NO_KILL");
	message_vision(HIR"
郭嵩阳缓缓抬起头，虎目逐渐恢复了神采。。。但却是一种妖异之气，全身的
肌肉迅速膨胀起来，仿佛要炸开一般。 

郭嵩阳抄起地上的长剑，仰天长啸，裂金穿云，发疯般怒吼道：杀！杀！杀！杀！杀！ \n\n\n"NOR,me);
	ob->kill_ob(me);
	ob->carry_object("obj/weapon/sword");
	ob->ccommand("wield sword");
	return 1;
}


string *event3_msg=	({
	
	HIW"\n忽然，一阵磔磔地狂笑由远至近迅速传来。。\n"NOR,
	
	HIW"\n“妙载，妙载！踏破铁鞋无觅处，得来全不费功夫，哈，哈，哈哈。” \n"NOR,
	
	HIW"\n一只白润如玉的手竟已伸到你眼前，还没等你回过神来，已从你手中抢走了无间木。\n"NOR,

	HIW"\n白玉手一翻，十根尖尖的手指插向你的心口，你吐呐尚未完毕，难道只得闭目等死？\n"NOR,

    	HIW"\n十根手指将要插入你心口的一刹那。\n"NOR,
    
    	HIC"\n那一刹那。。。。\n\n\n"NOR,
    	
	HIR"\n\n飞刀现。\n"NOR,
	
	HIR"小李飞刀，例不虚发。\n"NOR,
	
	HIR"\n    。。。。\n"NOR,
	
	HIR"你胸口一阵绞痛，还未看清究竟是发生了什么，已晕倒了过去。\n"NOR, 

});


void event3(object me, int count)
{
	object room, li;
	
	
	if ( !me || environment(me)!= this_object() ) 	return;
		
	tell_object(me,event3_msg[count]+"\n");
	if(++count==sizeof(event3_msg))
	{
		
		me->set_temp("maze/see_li",1);
		me->stop_busy();
		me->unconcious();
		room = find_object(AREA_FY"fysecret");
		if (!room) room = load_object(AREA_FY"fysecret");
		REWARD_D->riddle_set(me,"再闯金钱",4);
		me->move(room);
		return;
	}
	else call_out("event3",1,me,count);
	return ;
}

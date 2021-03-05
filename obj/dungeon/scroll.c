#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("卷轴", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
		set("teaching", "riposte");
		set("fy41","nonsense");
		set("required_exp", 5000000);
		set("required_class","none");
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	
	required = query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"弟子，"
			: "";
	msg = YEL"一卷绢册，散发着一股淡淡的清香，上面写着（ｒｅａｄ）\n"NOR;
	msg += sprintf(WHT"武功心诀：\t\t%s（%s）\n"
			  "学习条件：\t\t\%s\n"NOR,
			  query("name"),query("teaching"),
			  required,
			);
	return msg;
}

void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
    	object me;
    	mapping data, data2;
    	    
    	if(!arg || arg != "scroll"){
        	write("你想读什么？\n");
        	return 1;
        }
        
    	me = this_player();
	
	if (me->is_busy() || me->is_fighting()) {
		write("你现在还不能静下心来。\n");
		return 1;
	}
		
	if (me->query("class")!= query("required_class")) {
		write("这本卷轴上记录的武功心法不适合你来修炼，读了也没用。\n");
        	return 1;
        }
        
        data = F_LEVEL->exp_to_level(query("required_exp"));
        data2 = F_LEVEL->exp_to_level(me->query("combat_exp"));
        
        if (data2["level"] < data["level"]) {
        	
        	write("你还不能领悟卷轴上武功的精髓，至少需要"+ chinese_number(data["level"])+"等级。\n");
    		return 1;
    	}
    	
    	if (me->query("fy41/"+query("fy41"))) {
    		write("你已经学会这个卷轴上的武功了。\n");
    		return 1;
    	}
    	
    	message_vision(YEL"$N小心翼翼地打开卷轴。\n"NOR,me);
    	tell_object(me,YEL"你照着卷轴上的法门运气练功，果真是奥秘无穷。。。。\n"NOR);
    	tell_object(me,YEL"一炷香的功夫，你的武学修为又上了一层楼。\n"NOR);
    	message_vision(HIG"卷轴翩翩碎落，竟像蝴蝶一样飘散在风里了。\n"NOR,me);
    	me->perform_busy(1);
    	me->set("fy41/"+query("fy41"),1);
    	destruct(this_object());
    	return 1;
}
    
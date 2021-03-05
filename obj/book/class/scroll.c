// This is a modified version of Moon scroll, the 1->2-3 requirement is removed.

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
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	mapping data;

	seteuid(getuid());
	data = F_LEVEL->exp_to_level(query("required_exp"));
	required = chinese_number(data["level"])+"级以上";
	required += query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"弟子，"
			: "";

	required += "
掌握至少"+chinese_number(query("required_skill_level"))
				+"级"+SKILL_D(query("required_skill"))->name()+"\n";
	msg = YEL"一卷薄薄的丝绢，上面写着：
"NOR;
	msg += sprintf(WHT"武功心诀：%s（%s）
学习条件：%s\n"NOR,
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
    	mapping data;
    	    
    	if(!arg || arg != "scroll"){
        	write("你想读什么？\n");
        	return 1;
        }
        
    	me = this_player();
		if (me->query("class") != query("required_class"))
		{
			write("这本卷轴上记录的武功心法不适合你来修炼，读了也没用。\n");
        	return 1;
        }
        
		if (me->query_skill(query("required_skill"),1) < query("required_skill_level"))
		{
		write("你修为未到，读了也没用。\n");
        	return 1;
        }
        
        if (me->query("combat_exp") < query("required_exp")) {
        	data = F_LEVEL->exp_to_level(query("required_exp"));
        	write("你还不能领悟卷轴上武功的精髓，至少需要"+ chinese_number(data["level"])+"等级。\n");
    		return 1;
    	}
    	
    	if (me->query("scroll/"+query("required_skill")+"_"+query("teaching")) >= query("grade"))
		{
    		write("你已经学会这个卷轴上的武功了。\n");
    		return 1;
    	}
/*    	
    	if (me->query("annie/"+query("required_skill")+"_"+query("teaching")) + 1 < query("grade"))
		{
    		write("你尚未领悟这一门武功更为粗浅的入门技艺，不能躁进修习此功。\n");
    		return 1;
    	}
*/    	
    	message_vision(HIW"$N小心翼翼地打开卷轴。\n"NOR,me);
    	tell_object(me,HIC"你照着卷轴上的法门运气练功，果真是奥秘无穷．．．．\n"NOR);
    	tell_object(me,HIC"一炷香的功夫，你的武学修为又上了一层楼。\n"NOR);
    	message_vision(HIG"片刻，$N手中的卷轴翩翩碎落，像蝴蝶一样飘散在风中。\n"NOR,me);
    	me->perform_busy(1);
		me->set("scroll/"+query("required_skill")+"_"+query("teaching")	,query("grade"));
		destruct(this_object());
    	return 1;
}
    
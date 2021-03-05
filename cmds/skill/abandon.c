// abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;
void abandon_skill(string confirm, object me, string skill);
int zero_skill(object me, string arg);
mapping valid_types = ([
//		"array":        "阵法",
		"animal-training":  "训兽术",
		"axe":    	"斧法",
		"blade":        "刀法",
		"dagger":       "短兵刃",
		"dodge":        "闪躲术",
		"force":        "内功",
		"fork":         "叉法",
		"hammer":       "锤法",
		"iron-cloth": 	"硬功",
		"literate": 	"读写",
		"magic":        "法术",
		"move":         "轻功",
		"parry":        "招架",
		"perception":   "听风术",
		"scratching":   "符之术",
		"cursism" :	"降头术",
		"spells":       "咒文",
		"staff":        "杖法",
		"stealing":     "妙手术",
		"sword":        "剑法",
		"throwing":     "暗器",
		"unarmed":      "拳脚",
		"whip":     	"鞭法",
		"herb":		"药道",
		"spear":        "枪法",
		"musket":				"火枪",
]);



int main(object me, string arg)
{
	string err;
	
	if( !arg || arg=="" ) return notify_fail("你要放弃哪一项技能？\n");

	if(!find_object(SKILL_D(arg)) && file_size(SKILL_D(arg)+".c")<0) {
		return notify_fail("「" + arg + "」，有这种技能吗？\n");	
	}
	/*if(!load_object(SKILL_D(arg)+".c")) 
		return notify_fail("「" + arg + "」，有这种技能吗？\n");
	*/	
    seteuid(getuid());
    err = catch( call_other(SKILL_D(arg)+".c", "???") );
    if (err)
       printf( "发生错误：\n%s\n", err );
	
	if( !me->query_skill(arg,1) && !zero_skill(me,arg))
		return notify_fail("你并没有学过这项技能。\n");
		
	if (arg == "magic" || arg == "force" || arg == "spells")
		return notify_fail("这项基本技能影响你的精气神数值，无法放弃。\n");
		
	write(HIY"\n「放弃」是指将这项技能从你人物的资料中删除，如果你以后还要练，必须从零开
始重练，请务必考虑清楚。\n\n"NOR);
	
	if (me->query("annie/skill_cost/"+arg)>0) {
		write(HIY"你已经在这门技能上花费了"+me->query("annie/skill_cost/"+arg)+"点潜能，建议你使用ｒｅｆｕｎｄ的方式收回这些潜
能学其他东西，ｒｅｆｕｎｄ的方式请参看ｈｅｌｐ　ｎｅｗｂｉｅ的第１４条，本
次指令中断。\n\n"NOR);
		return 1;
	}
	
	write("你确定放弃继续学习［"HIR + SKILL_D(arg)->name() + NOR"］，是否要继续？(yes/no)\n");
	input_to( (: abandon_skill :), me, arg);
	return 1;
}

void abandon_skill(string confirm, object me, string skill) 
{
	if (! (confirm == "yes" || confirm == "YES")) 
		write("你出了一身冷汗，好险！\n");
	else    {
        	if(me->query_skill(skill,1)>50)
        	log_file("skills/ABANDON",
        	  sprintf("%s(%s)在%s放弃了%d级%s。\n",
        	  me->name(1),geteuid(me),ctime(time()),me->query_skill(skill,1),skill));
		me->delete_skill(skill);
		me->reset_action();
		write("你决定放弃继续学习" + SKILL_D(skill)->name() + "。\n");
	}
}


int zero_skill(object me, string arg) {
	mapping learned_skill_points;
	
	learned_skill_points=me->query_learned();
	if (!mapp(learned_skill_points))	return 0;
	if (!learned_skill_points[arg]) return 0;
	return 1;
}


	
	
	

int help()
{
	write(@TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式：abandon <技能名称>[0m
[0;1;37m────────────────────────────────[0m

放弃一项你所学的技能，注意这里所说的「放弃」是指将这项技能从你人
物的资料中删除，如果你以后还要练，必须从0开始重练，请务必考虑清
楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由於
我们假设你的人物随时都会从他／她的各种动作、战斗中学习，因此有些
技能会因为你经常地使用而出现在你的技能列表中，这个人物就必须花费
一些精神去「记住」所学过的一切，然而，人的资质各有不同，灵性高的
人能够学习许多技能而成为多才多艺的才子，灵性较差的人就只能专心於
特定几项技能，如果你学的技能种类太多，超过你的灵性，你会发现人物
的学习速度将比只学几种技能的人慢，超过越多，学习效果低落的情况越
严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著
超人的意志力练下去，不过这将会多花费你许多宝贵的时间。

注：学习技能总数＞灵性＋１时学习效率将降低。
[0;1;37m────────────────────────────────[0m
TEXT
	);
	return 1;
}

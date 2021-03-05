// /adm/daemons/mfd.c
// written by akuma for magic find
// 2003-7-19
// version 0.9
// 基本完成了，就差具体公式调整了
// 还有，属性加成和imbue没有弄呢
#include <ansi.h>
int time=0;
void modify_vo(object,int,string);
mapping types = ([
	"cloth":	"布衣",
	"spear":	"长枪",
]);
mapping attr_types = ([
	"strength":	"膂力",
	"courage":	"勇气",
	"intelligence":	"才智",
	"spirituality":	"灵性",
	"composure":	"定力",
	"constitution":	"根骨",
	"karma":	"福缘",
]);
	
string* lv_attr=({"粗制滥造的","低劣的","普通的","高级的","完美的","神话般的"});
string* lv_color=({
	HIY,//攻防高	
	HIG,//属性加成	
	MAG,//没有属性
	BLU,//攻防低
});
	
void create()
{
        seteuid(getuid());

}

object new_vo(int lv,string type)
{
	string file;
	object newvo;
	//如果是错误的类型
	if( undefinedp(types[type]) )
	{
		newvo=new("/obj/money/coin");
		return newvo;
	}
	//如果时间间隔太小了
	if( time() - time < 60 )
	{
		newvo=new("/std/vobase/"+type);
		return newvo;
	}
	//否则
	time=time();
	file=sprintf("/vo/%s/%d",type,time());
	call_other(file,"???");
	// nobody would delete the sentense below
	write("");
	newvo=new(file);
	modify_vo(newvo,lv,type);
	CHANNEL_D->do_channel( this_object(), "sys","CREATE ONE VO FOR MF");
	return newvo;
}

void modify_vo(object newvo,int lv,string type)
{
	string name;
	int namelv;
	int rand;
	//设置名字	
	namelv=lv/10;
	if(namelv<0) namelv=0;
	if(namelv>sizeof(lv_attr)-1) namelv=sizeof(lv_attr)-1;
	name=lv_attr[namelv]+types[type];
	//有什么属性？
	
	rand=(random(10));//3-9都是低攻防所以。。。。
	if(rand==0)//是高攻防的
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv+random(random(lv)));
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv+random(random(lv)));
		}

		newvo->set("value",lv*255);
		name=lv_color[0]+name+NOR;
	}		

	else if(rand==1)//属性加成
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv);
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv);
		}
		//添加属性
//这里没有写完整
		newvo->set("armor_prop/intelligence",1);
//明天修改
		//
		newvo->set("value",lv*288);
		name=lv_color[1]+name+NOR;
	}		
	else if(rand==2)//是没属性的
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv);
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv);
		}

		newvo->set("value",lv*222);

		name=lv_color[2]+name+NOR;
	}		
	else//low 
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv-random(random(lv)));
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv-random(random(lv)));
		}

		newvo->set("value",lv*188);

		name=lv_color[3]+name+NOR;

	}
	
	newvo->set("name",name);
	newvo->save();
}

void change_vo(object vo,mixed xx)
{
	//do what ne?
}
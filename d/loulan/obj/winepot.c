inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("精制酒壶", ({ "wine pot" , "winepot"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个精制的调酒壶，传说是战国时期
的酿酒大师禹大师采集千年犀牛角，上古温玉和金银铜铁锡五金
精华苦心制成。上边还刻了些奇怪的花纹。据说号称天下第一佳
酿的【孔雀开屏】只有这只酒壶采能调配出（ｍｉx）。\n");
		set("value", 1);
	}
}

void init()
{
//	if(this_player()==environment())
	add_action("do_mix","mix");
}

int do_mix()
{
	int i,old,wolf,zhu,nu,gao,jian,dong;
	object peacock,me,*inv;
	object oldwine,wolfwine,zhuwine,nuwine,gaowine,jianwine,dongwine;
	me = this_player();
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if((inv[i]->query("name") == "古城烧")&&(inv[i]->query("liquid/name") == "古城烧"))
		{old = 1; oldwine = inv[i];}
		if((inv[i]->query("name") == RED"狼酒袋"NOR)&&(inv[i]->query("liquid/name") == "狼酒"))
		{wolf = 1; wolfwine = inv[i];} 
		if((inv[i]->query("name") == "竹叶青酒袋")&&(inv[i]->query("liquid/name") == "竹叶青"))
		{zhu = 1; zhuwine = inv[i];}
		if((inv[i]->query("name") == "绍兴女儿红")&&(inv[i]->query("liquid/name") == "绍兴女儿红"))
		{nu = 1;  nuwine = inv[i];}
		
		if((inv[i]->query("name") == "红高粱")&&(inv[i]->query("liquid/name") == "红高粱"))
		{gao = 1; gaowine = inv[i];}
		
		if((inv[i]->query("name") == "剑南春酒袋")&&(inv[i]->query("liquid/name") == "剑南春"))
		{jian = 1; jianwine = inv[i];}
		if((inv[i]->query("name") == "董酒")&&(inv[i]->query("liquid/name") == "董酒"))
		{dong = 1; dongwine = inv[i];}
	}
	if( old==1 && wolf==1 && zhu==1 && nu==1 && gao==1 && jian==1 && dong==1 )
	{
			destruct(oldwine);
	        destruct(wolfwine);
	        destruct(zhuwine);
	        destruct(nuwine);
	        destruct(gaowine);
	        destruct(jianwine);
	        destruct(dongwine); 
        	peacock = new("/d/loulan/obj/bottle");
			peacock->move(me);
			message_vision("$N把身上带的七种名酒小心翼翼的倒进精制酒壶，调制出一壶酒香四\n溢的【孔雀开屏】．\n",this_player());
		    REWARD_D->riddle_done( this_player(),"孔雀开屏",10, 1);
	        destruct(this_object());
	}
	else 
		message_vision("$N把精制酒壶摆弄了几下，但是似乎缺少点材料，什么也做不出来．\n",this_player());
	return 1;
}

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","如意人魔连环八步");
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("skill_class","demon");
	set("dodge_msg", ({
	        "$n一招“魔幻虚影”，全身化出千百个身影躲闪开了$N这一招。\n",
	        "$n气聚丹田，一招“重生魔寐”，身形急缩，躲开$N那致命一击。\n",
	        "$n真气荡漾，清啸连连，一招“魔魇懵懵”，滑出丈外。\n",
	        "$n双脚轻踏九曲，一招“魔光旖旎”，身形无比美妙地荡开数尺。\n",
	        "$n使出如意人魔连环八步中的“魔影娉婷”，身形化实为虚地躲开了$N这一招。\n",
	        "$n腾空一跃，双脚凌空虚踏，一招“魔冲霄汉”，躲开数尺。\n",
	        "$n身形晃动，一招“魔心穹隆”，全身化作无数虚影掠出丈外。\n",
	        "$n猛吸一口气，一招“奇魔异形”，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
		}) );
	
}



.include "asm/macros.inc"
.include "constants/constants.inc"

.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08019928 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r3, #0xc0
	lsls r3, r3, #0x12
	adds r0, r1, r3
	ldr r2, _0801992C @ =gMultiplayerPlayerTasks
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	adds r6, r4, r3
	ldr r0, _08019930 @ =IWRAM_START + 0x10
	adds r0, r1, r0
	str r0, [sp]
	ldr r2, _08019934 @ =IWRAM_START+4
	adds r2, r2, r1
	mov sl, r2
	adds r3, #0x50
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08019938 @ =gCamera
	ldr r0, [r2]
	subs r1, r1, r0
	adds r5, r2, #0
	cmp r1, #0xf0
	bhi _080198F4
	adds r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #4]
	subs r0, r1, r0
	cmp r0, #0
	blt _080198F4
	cmp r0, #0xa0
	bgt _080198F4
	b _08019C96
_080198F4:
	adds r2, r6, #0
	adds r2, #0x50
	ldrh r0, [r2]
	subs r0, #0x78
	ldr r3, [r5]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	adds r1, r6, #0
	adds r1, #0x52
	ldrh r0, [r1]
	subs r0, #0x50
	ldr r5, [r5, #4]
	subs r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r7, r2, #0
	cmp r3, r0
	ble _08019944
	ldr r0, _0801993C @ =0xFFFFFA60
	adds r4, r3, r0
	ldr r3, _08019940 @ =0xFFFFFCA0
	b _0801994E
	.align 2, 0
_08019928: .4byte gCurTask
_0801992C: .4byte gMultiplayerPlayerTasks
_08019930: .4byte IWRAM_START + 0x10
_08019934: .4byte IWRAM_START+4
_08019938: .4byte gCamera
_0801993C: .4byte 0xFFFFFA60
_08019940: .4byte 0xFFFFFCA0
_08019944:
	movs r0, #0xb4
	lsls r0, r0, #3
	adds r4, r3, r0
	movs r3, #0xd8
	lsls r3, r3, #2
_0801994E:
	adds r2, r5, r3
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, r0, r4
	cmp r0, #0xf0
	bhi _0801996A
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r0, r2
	cmp r0, #0
	blt _0801996A
	cmp r0, #0xa0
	bgt _0801996A
	b _08019C96
_0801996A:
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, #0x78
	subs r4, r0, r4
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, #0x50
	subs r2, r0, r2
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _08019986
	rsbs r1, r1, #0
_08019986:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08019990
	rsbs r0, r0, #0
_08019990:
	cmp r0, r1
	bge _08019996
	adds r0, r1, #0
_08019996:
	adds r3, r4, #0
	cmp r4, #0
	bge _0801999E
	rsbs r3, r4, #0
_0801999E:
	adds r1, r2, #0
	cmp r2, #0
	bge _080199A6
	rsbs r1, r2, #0
_080199A6:
	cmp r1, r3
	bge _080199AC
	adds r1, r3, #0
_080199AC:
	cmp r0, r1
	ble _080199BA
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r0, r2, #0x10
	lsrs r6, r0, #0x10
_080199BA:
	mov r2, ip
	lsls r1, r2, #0x10
	lsrs r4, r1, #0x10
	lsls r0, r6, #0x10
	lsrs r3, r0, #0x10
	adds r5, r1, #0
	str r0, [sp, #4]
	ldr r6, [sp]
	adds r6, #0x22
	cmp r5, #0
	beq _08019A26
	cmp r0, #0
	beq _08019A26
	lsls r2, r3, #0x10
	b _08019A0C
_080199D8:
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r2, r2, r0
	lsls r2, r2, #0xf
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r3, r1, #0x10
	lsrs r4, r2, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _080199F8
	rsbs r0, r0, #0
_080199F8:
	cmp r0, #1
	ble _08019A26
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0
	bge _08019A08
	rsbs r1, r1, #0
_08019A08:
	cmp r1, #1
	ble _08019A26
_08019A0C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08019A16
	rsbs r0, r0, #0
_08019A16:
	cmp r0, #0x7f
	bgt _080199D8
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _08019A22
	rsbs r0, r0, #0
_08019A22:
	cmp r0, #0x7f
	bgt _080199D8
_08019A26:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, #0
	cmp r1, #0
	bge _08019A32
	rsbs r0, r1, #0
_08019A32:
	cmp r0, #1
	bgt _08019A46
	lsls r0, r3, #0x10
	movs r2, #0xc0
	lsls r2, r2, #2
	cmp r0, #0
	ble _08019A6A
	movs r2, #0x80
	lsls r2, r2, #1
	b _08019A6A
_08019A46:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	cmp r0, #0
	bge _08019A52
	rsbs r2, r0, #0
_08019A52:
	cmp r2, #1
	bgt _08019A62
	movs r2, #0x80
	lsls r2, r2, #2
	cmp r1, #0
	ble _08019A6A
	movs r2, #0
	b _08019A6A
_08019A62:
	bl sub_8004418
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08019A6A:
	lsls r2, r2, #0x10
	asrs r0, r2, #0x10
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r3, _08019A9C @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	mov r1, sl
	strh r0, [r1]
	asrs r0, r5, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	ldr r3, [sp, #4]
	asrs r0, r3, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08019AA0 @ =0x0000FFFF
	adds r4, r2, #0
	cmp r1, r0
	bgt _08019AA4
	movs r0, #0x18
	b _08019AA6
	.align 2, 0
_08019A9C: .4byte 0x000003FF
_08019AA0: .4byte 0x0000FFFF
_08019AA4:
	movs r0, #0x10
_08019AA6:
	strb r0, [r6]
	movs r2, #0xc0
	lsls r2, r2, #0x13
	cmp r1, r2
	ble _08019ABA
	movs r0, #0x40
	mov r1, sl
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	b _08019AEC
_08019ABA:
	ldr r0, _08019ACC @ =0x0000FFFF
	cmp r1, r0
	bgt _08019AD0
	movs r0, #0xf0
	lsls r0, r0, #1
	mov r2, sl
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	b _08019AEC
	.align 2, 0
_08019ACC: .4byte 0x0000FFFF
_08019AD0:
	subs r1, r2, r1
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08019AF8 @ =0x000005FF
	bl Div
	adds r0, #0x40
	mov r3, sl
	strh r0, [r3, #2]
	strh r0, [r3, #4]
_08019AEC:
	asrs r4, r4, #0x10
	cmp r4, #0
	bne _08019AFC
	movs r5, #0x50
_08019AF4:
	movs r0, #0xf0
	b _08019C5A
	.align 2, 0
_08019AF8: .4byte 0x000005FF
_08019AFC:
	movs r6, #0x80
	lsls r6, r6, #1
	cmp r4, r6
	bne _08019B0A
	movs r5, #0xa0
	movs r0, #0x78
	b _08019C5A
_08019B0A:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r4, r0
	bne _08019B16
	movs r5, #0x50
	b _08019C58
_08019B16:
	movs r0, #0xc0
	lsls r0, r0, #2
	mov sb, r0
	cmp r4, sb
	bne _08019B26
	movs r5, #0
	movs r0, #0x78
	b _08019C5A
_08019B26:
	cmp r5, #0
	ble _08019B8C
	ldr r7, _08019B70 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	lsls r0, r0, #8
	adds r1, r4, r6
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x16
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	asrs r1, r1, #5
	adds r1, #0x50
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r1, [sp, #4]
	cmp r1, #0
	ble _08019B78
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _08019AF4
	movs r5, #0xa0
	subs r1, r6, r4
	ldr r0, _08019B74 @ =0x000003FF
	ands r1, r0
	b _08019BDE
	.align 2, 0
_08019B70: .4byte gSineTable
_08019B74: .4byte 0x000003FF
_08019B78:
	lsls r0, r5, #0x10
	cmp r0, #0
	bge _08019AF4
	movs r5, #0
	subs r1, r6, r4
	ldr r0, _08019B88 @ =0x000003FF
	ands r1, r0
	b _08019C28
	.align 2, 0
_08019B88: .4byte 0x000003FF
_08019B8C:
	ldr r7, _08019C0C @ =gSineTable
	ldr r2, _08019C10 @ =0xFFFFFE00
	adds r1, r4, r2
	ldr r3, _08019C14 @ =0x000003FF
	mov r8, r3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	lsls r0, r0, #8
	adds r1, r1, r6
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x16
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	asrs r1, r1, #5
	movs r0, #0x50
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _08019C18
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _08019C58
	movs r5, #0xa0
	mov r2, sb
	subs r1, r2, r4
	mov r3, r8
	ands r1, r3
_08019BDE:
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	lsls r0, r0, #8
	adds r1, r1, r6
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x16
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	asrs r1, r1, #4
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	b _08019C5A
	.align 2, 0
_08019C0C: .4byte gSineTable
_08019C10: .4byte 0xFFFFFE00
_08019C14: .4byte 0x000003FF
_08019C18:
	lsls r0, r5, #0x10
	cmp r0, #0
	bge _08019C58
	movs r5, #0
	mov r0, sb
	subs r1, r0, r4
	mov r2, r8
	ands r1, r2
_08019C28:
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	lsls r0, r0, #8
	adds r1, r1, r6
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x16
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	asrs r1, r1, #4
	movs r0, #0x78
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08019C5A
_08019C58:
	movs r0, #0
_08019C5A:
	mov r3, sl
	strh r0, [r3, #6]
	strh r5, [r3, #8]
	ldr r1, [sp]
	ldr r0, [r1, #0x10]
	movs r1, #0x20
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp]
	str r0, [r2, #0x10]
	ldr r2, _08019CA8 @ =gUnknown_030054B8
	ldrb r1, [r2]
	adds r0, r1, #1
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, [sp]
	ldr r0, [r3, #0x10]
	orrs r0, r1
	str r0, [r3, #0x10]
	ldr r0, [sp]
	bl UpdateSpriteAnimation
	ldr r0, [sp]
	mov r1, sl
	bl TransformSprite
	ldr r0, [sp]
	bl DisplaySprite
_08019C96:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019CA8: .4byte gUnknown_030054B8

	
.syntax divided

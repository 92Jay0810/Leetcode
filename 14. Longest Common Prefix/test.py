class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        common = strs[0]
        for str in strs:
            sub_common = []
            for i, substr in enumerate(str):
                if i < len(common) and common[i] == substr:
                    sub_common.append(common[i])
                else:
                    break
            common = sub_common
        return "".join(common)

# Masai Library - Technical Documentation Hub  
**Live Website:** [https://masailibrary.com/](https://masailibrary.com/)  
*A static website hosting specialized PDF resources using AWS infrastructure*

[![AWS Deployment](https://img.shields.io/badge/AWS-Deployed-orange?logo=amazon-aws)](https://masailibrary.com)
[![Infrastructure as Code](https://img.shields.io/badge/IaC-CloudFormation-blueviolet)](https://aws.amazon.com/cloudformation/)
[![Static Website](https://img.shields.io/badge/Architecture-Static%20S3%20%2B%20CloudFront-green)](https://aws.amazon.com/s3/static-web-hosting/)

## 📂 Project Structure
```
aws-static-website-portfolio/
├── infrastructure/
│   └── cloudformation.yml      # AWS deployment template
├── src/                        # Website source files
│   ├── index.html              # Main page
├── analytics/                  # Usage analytics
│   ├── coremetrics.md          # Key performance metrics
|   |__ growthstrategy.md       # Growth Strategy Used
│   ├── user_demographics.md    # User statistics
│   ├── traffic_sources.md      # Traffic channels
│   └── performance_insights.md # Optimization notes
│__ .gitattributes              # Git configuration
└── README.md                   # Project overview
```

## 🧠 Technical Architecture
```
┌─────────────────┐     ┌──────────────────┐
│     User        │     │  GitHub Actions  │
└────────┬────────┘     └─────────┬────────┘
         │                        │
         ▼                        ▼
┌──────────────────┐     ┌──────────────────┐
│ CloudFront CDN   ◄─────┤    S3 Bucket     │
└──────────────────┘     └──────────────────┘
         ▲
         │
┌────────┴────────┐
│    AWS WAF      │
└─────────────────┘
```

**Core Components:**
- **AWS S3**: Static website hosting for HTML/CSS/JS files
- **CloudFront CDN**: Global content delivery
- **AWS WAF**: Basic security protection
- **CloudFormation**: Infrastructure deployment template

## 📊 Actual Analytics Metrics (First 28 Days)

| Metric | Value |
|--------|-------|
| **Active Users** | 897 |
| **New Users** | 896 |
| **PDF Downloads** | 5.9K |
| **Avg Session Duration** | 1m 50s |
| **Bounce Rate** | 42.4% |

**User Geography:**
1. 🇮🇳 India: 811 users 
2. 🇺🇸 United States: 52 users
3. 🇫🇷 France: 10 users

## 🚀 Deployment Process

**Manual Deployment:**
```bash
# Deploy infrastructure
aws cloudformation deploy \
  --template-file infrastructure/cloudformation.yml \
  --stack-name masailibrary-prod

# Upload website files
aws s3 sync src/ s3://masailibrary.com --delete
```

## 🔍 Analytics Implementation

The analytics tracking is implemented through Google Analytics with event tracking for key actions:

```html
<!-- Example GA event tracking -->
<script>
document.getElementById('download-button').addEventListener('click', function() {
  gtag('event', 'file_download', {
    'file_name': 'document.pdf'
  });
});
</script>
```

**Tracked Events:**
- `file_download` (PDF downloads)
- `session_start` (User sessions)
- `page_view` (Page visits)

## 📈 Growth Opportunities

Based on current analytics:

1. **Traffic Sources**:
   - 92% from direct/organic search
   - Opportunity to develop social/referral channels

2. **User Retention**:
   - 97% of active users are new visitors
   - Potential for account system to increase retention

3. **Content Expansion**:
   - High demand for PDFs (5.9K downloads)
   - Opportunity to add categorization and search

## 🔗 Resources
- [Live Website](https://masailibrary.com/)
- [CloudFormation Template](/Infrastructure/cloudformation.yml)
- [Core Metrics Report](/Analytics/coremetrics.md)

## 💌 Contact
**Maintainer:** Aryaman Parashar Behera
**Email:** parashararyaman108@gmail.com 

---

*This project uses AWS CloudFormation for infrastructure management and Google Analytics for usage tracking. All metrics shown are actual data from production.*
